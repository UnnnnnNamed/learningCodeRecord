package CET6Helper.Client;

import javax.swing.*;
import java.awt.*;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Objects;

public class ButtonController {
    public JButton jButton;
            public ButtonController(int x, int y, int width, int height, String s){//实例化按钮并设置位置大小
        this.jButton = new JButton();
        this.jButton.setText(s);
        this.jButton.setBounds(x,y,width,height);
    }
    public static void buttonSetter(JLabel label,ButtonController buttonOne, ButtonController buttonTwo,
                                    ButtonController buttonThree, ButtonController buttonFour) {//用于设置各个按钮上写的中文意思
        label.setText(WordController.theWord);
        buttonOne.jButton.setText(WordController.meanings[0]);
        buttonTwo.jButton.setText(WordController.meanings[1]);
        buttonThree.jButton.setText(WordController.meanings[2]);
        buttonFour.jButton.setText(WordController.meanings[3]);
    }
    public static void buttonFunChange(ButtonController button,JFrame thisFrame,JFrame nextFrame){//切换窗口，thisFrame不可视，nextFrame可视
        button.jButton.addActionListener(e -> {
            thisFrame.dispose();
            nextFrame.setVisible(true);
        });
    }
    public static void buttonFunBegin(ButtonController button, Socket socket) throws IOException {//向服务端发出开始指令
        PrintStream stream = new PrintStream(socket.getOutputStream());
        button.jButton.addActionListener(e -> stream.println("BEGIN"));
    }
    public static void buttonFunQuit(ButtonController button){//退出系统
        button.jButton.addActionListener(e -> System.exit(0));
    }
    public static void buttonFunAnswerChoose(ButtonController button,Socket socket) {
        button.jButton.addActionListener(e -> {
            if (Objects.equals(WordController.rightAnswer, button.jButton.getText())) {//选择了答案，答案正确，选项设置为绿色
                WordController.addCorrectWord();
                WindowController.mark += 1;
                WindowController.labelRight.setText("恭喜你回答正确！");
                button.jButton.setBackground(Color.GREEN);
                buttonSetUnable();
            } else {//选择了答案，答案错误，选项设置为红色
                WordController.addWrongWord(true);
                WindowController.mark -= 2;
                WindowController.labelRight.setText("回答错误！正确答案：" + WordController.rightAnswer);
                button.jButton.setBackground(Color.RED);
                buttonSetUnable();
            }
            try {
                WindowController.markChange(socket);//改变显示的分数
            } catch (InterruptedException | IOException ex) {
                throw new RuntimeException(ex);
            }
        });
    }
    public static void buttonFunBackToMainWindow(ButtonController button, Socket socket) throws IOException {
        //回到主界面，发出已返回主界面，本次答题结束的指令
        PrintStream stream = new PrintStream(socket.getOutputStream());
        button.jButton.addActionListener(e -> {
            stream.println("BACK");
            WindowController.learningWindow.dispose();
            WindowController.mainWindow.setVisible(true);
            WindowController.mark =10;
            WindowController.labelMark.setText("分数:"+WindowController.mark);
            button.jButton.setEnabled(false);
            WindowController.windowInitialization();
            WindowController.creatReviewWindow();
        });
    }
    public static void buttonSetUnable() {
        //选完答案或未答后，将正确答案用绿色高亮，按钮设置为不可用
        if (Objects.equals(WordController.rightAnswer, WindowController.buttonOne.jButton.getText()))
            WindowController.buttonOne.jButton.setBackground(Color.GREEN);
        else if (Objects.equals(WordController.rightAnswer, WindowController.buttonTwo.jButton.getText()))
            WindowController.buttonTwo.jButton.setBackground(Color.GREEN);
        else if (Objects.equals(WordController.rightAnswer, WindowController.buttonThree.jButton.getText()))
            WindowController.buttonThree.jButton.setBackground(Color.GREEN);
        else if (Objects.equals(WordController.rightAnswer, WindowController.buttonFour.jButton.getText()))
            WindowController.buttonFour.jButton.setBackground(Color.GREEN);
        WindowController.buttonOne.jButton.setEnabled(false);
        WindowController.buttonTwo.jButton.setEnabled(false);
        WindowController.buttonThree.jButton.setEnabled(false);
        WindowController.buttonFour.jButton.setEnabled(false);
    }
    public static void buttonSetEnabled(){
        //按钮设置为无色，可用
        WindowController.buttonOne.jButton.setBackground(null);
        WindowController.buttonTwo.jButton.setBackground(null);
        WindowController.buttonThree.jButton.setBackground(null);
        WindowController.buttonFour.jButton.setBackground(null);
        WindowController.buttonOne.jButton.setEnabled(true);
        WindowController.buttonTwo.jButton.setEnabled(true);
        WindowController.buttonThree.jButton.setEnabled(true);
        WindowController.buttonFour.jButton.setEnabled(true);
        WindowController.labelRight.setText(null);
    }
}
