package CET6Helper.Client;

import javax.swing.*;
import java.awt.*;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Timer;
import java.util.TimerTask;

public class WindowController extends JFrame{
    //在多个类中使用比较方便，应该可以优化
    public static int mark = 10 ;
    public static JFrame mainWindow = new JFrame("CET6单词学习助手");
    public static JFrame learningWindow = new JFrame("正在学习");
    public static JFrame reviewWindow = new JFrame("正在复习");
    //learningWindow中的组件
    public static ButtonController buttonOne = new ButtonController(500,75,300,100,"");
    public static ButtonController buttonTwo = new ButtonController(500,225,300,100,"");
    public static ButtonController buttonThree = new ButtonController(500,375,300,100,"");
    public static ButtonController buttonFour = new ButtonController(500,525,300,100,"");
    public static ButtonController buttonBackToMain = new ButtonController(500,675,300,100,"返回主界面");
    public static JLabel fallingWord = new JLabel("准备开始");
    public static JLabel labelMark = new JLabel("分数:"+ mark);
    public static JLabel labelEnd = new JLabel();
    public static JLabel labelRight = new JLabel();
    public static Timer timer;
    //mainWindow中用于修改设置的组件
    public static JTextField waitingTime = new JTextField("300");//每题开始前单词停留的时间
    public static JTextField readyTime = new JTextField("1000");//每题结束后准备下一题，包括开头准备第一题的时间
    public static JTextField fallSpeed = new JTextField("2");//单词下落速度
    public static void creatWindow(Socket socket) throws IOException {
        creatMainWindow(socket);
        creatLearningWindow(socket);
        creatReviewWindow();
    }
    /*

     ***用在类内的几个方法***

     */
    private static void creatMainWindow(Socket socket) throws IOException {
        //各个组件，以及设置按钮位置
        ButtonController buttonBegin = new ButtonController(275,325,250,100,"开始学习");
        ButtonController buttonReview = new ButtonController(275,475,250,100,"词汇复习");
        ButtonController buttonQuit = new ButtonController(275,625,250,100,"退出程序");
        final JLabel title = new JLabel("CET6-词汇助手");
        final JLabel wait = new JLabel("每题停留时间(毫秒):");
        final JLabel ready = new JLabel("每题准备时间(毫秒):");
        final JLabel speed = new JLabel("速度:");
        //字体设置
        Font buttonFont = new Font("宋体",Font.BOLD,20);
        Font dataSetterFont = new Font("宋体",Font.BOLD ,20);
        wait.setFont(dataSetterFont);
        ready.setFont(dataSetterFont);
        speed.setFont(dataSetterFont);
        waitingTime.setFont(dataSetterFont);
        readyTime.setFont(dataSetterFont);
        fallSpeed.setFont(dataSetterFont);
        buttonBegin.jButton.setFont(buttonFont);
        buttonReview.jButton.setFont(buttonFont);
        buttonQuit.jButton.setFont(buttonFont);
        title.setFont(new Font("宋体",Font.BOLD,50));
        //按钮功能
        ButtonController.buttonFunChange(buttonBegin, mainWindow, learningWindow);
        ButtonController.buttonFunChange(buttonReview, mainWindow, reviewWindow);
        ButtonController.buttonFunBegin(buttonBegin,socket);
        ButtonController.buttonFunQuit(buttonQuit);
        //按钮以外组件设置位置、大小，并加入主界面
        mainWindow.setLayout(null);
        title.setBounds(233,100,500,100);
        wait.setBounds(233,200,200,30);
        ready.setBounds(233,235,200,30);
        speed.setBounds(233,270,200,30);
        waitingTime.setBounds(433,200,130,30);
        readyTime.setBounds(433,235,130,30);
        fallSpeed.setBounds(433,270,130,30);
        mainWindow.setBounds(560,140,800,800);
        mainWindow.add(title);
        mainWindow.add(waitingTime);
        mainWindow.add(readyTime);
        mainWindow.add(fallSpeed);
        mainWindow.add(wait);
        mainWindow.add(ready);
        mainWindow.add(speed);
        mainWindow.add(buttonBegin.jButton);
        mainWindow.add(buttonReview.jButton);
        mainWindow.add(buttonQuit.jButton);
        mainWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainWindow.setVisible(true);
    }
    private static void creatLearningWindow(Socket socket) throws IOException {
        //字体设置
        Font buttonFont = new Font("宋体",Font.BOLD,20);
        Font labelFont = new Font("宋体",Font.BOLD,20);
        labelMark.setFont(labelFont);
        labelRight.setFont(labelFont);
        labelEnd.setFont(labelFont);
        buttonOne.jButton.setFont(buttonFont);
        buttonTwo.jButton.setFont(buttonFont);
        buttonThree.jButton.setFont(buttonFont);
        buttonFour.jButton.setFont(buttonFont);
        buttonBackToMain.jButton.setFont(buttonFont);
        fallingWord.setFont(new Font("宋体",Font.BOLD,30));
        //按钮功能设置
        ButtonController.buttonFunAnswerChoose(buttonOne,socket);
        ButtonController.buttonFunAnswerChoose(buttonTwo,socket);
        ButtonController.buttonFunAnswerChoose(buttonThree,socket);
        ButtonController.buttonFunAnswerChoose(buttonFour,socket);
        //答题结束后返回主界面的按钮
        ButtonController.buttonFunBackToMainWindow(buttonBackToMain,socket);
        //组件位置、大小设置并加入到窗口中
        learningWindow.setLayout(null);
        fallingWord.setBounds(150,75,500,100);
        labelMark.setBounds(50,80,500,100);
        labelRight.setBounds(50,150,1000,100);
        labelEnd.setBounds(50,220,500,100);
        learningWindow.setBounds(560,90,800,900);
        learningWindow.add(buttonOne.jButton);
        learningWindow.add(buttonTwo.jButton);
        learningWindow.add(buttonThree.jButton);
        learningWindow.add(buttonFour.jButton);
        learningWindow.add(buttonBackToMain.jButton);
        learningWindow.add(fallingWord);
        learningWindow.add(labelMark);
        learningWindow.add(labelRight);
        learningWindow.add(labelEnd);
        learningWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public static void creatReviewWindow() {
        //各个组件实例化
        JLabel masterLabel = new JLabel("已掌握单词");
        JLabel notMasterLabel = new JLabel("未掌握单词");
        JTable masterTable = new JTable(WordController.masterArray, new String[]{"单词", "意义"});
        JTable notMasterTable = new JTable(WordController.notMasterArray,new String[]{"单词","意义","原因"});
        ButtonController buttonBack = new ButtonController(1150,725,300,100,"返回主界面");
        JScrollPane masterPane = new JScrollPane(masterTable);
        JScrollPane notMasterPane = new JScrollPane(notMasterTable);
        //设置字体
        masterLabel.setFont(new Font("宋体",Font.BOLD,20));
        notMasterLabel.setFont(new Font("宋体",Font.BOLD,20));
        masterTable.setFont(new Font("宋体",Font.BOLD,20));
        notMasterTable.setFont(new Font("宋体",Font.BOLD,20));
        buttonBack.jButton.setFont(new Font("宋体",Font.BOLD,30));
        //按钮功能设置
        ButtonController.buttonFunChange(buttonBack, reviewWindow, mainWindow);
        //设置各个组件位置大小，并添加到窗口中
        reviewWindow.setLayout(null);
        masterTable.setRowHeight(25);
        notMasterTable.setRowHeight(25);
        masterLabel.setBounds(50,0,500,100);
        notMasterLabel.setBounds(640,0,500,100);
        masterPane.setBounds(50,75,540,625);
        notMasterPane.setBounds(640,75,810,625);
        reviewWindow.setBounds(210,90,1500,900);
        reviewWindow.add(masterLabel);
        reviewWindow.add(notMasterLabel);
        reviewWindow.add(masterPane);
        reviewWindow.add(notMasterPane);
        reviewWindow.add(buttonBack.jButton);
        //得到复习列表
        WordController.getTheReviewList();
        reviewWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    /*

        ***用在类外的几个方法***

     */
    public static void markChange(Socket socket) throws InterruptedException, IOException {

        labelMark.setText("分数:" + mark);
        PrintStream stream = new PrintStream(socket.getOutputStream());
        timer.cancel();//暂停LearningWindow中的下落
        if(mark >0&& mark <20) {
            stream.println("NEXT");//对服务端发出指令，继续得到新单词
        }else if(mark >=20){
            labelEnd.setText("恭喜你通过了本次学习");
            WindowController.fallingWord.setLocation(150,75);//单词复位
            buttonBackToMain.jButton.setEnabled(true);//游戏结束，返回主界面按钮启用
        }else{
            labelMark.setText("分数:0");
            labelEnd.setText("分数为0，学习结束");
            WindowController.fallingWord.setLocation(150,75);//单词复位
            buttonBackToMain.jButton.setEnabled(true);//游戏结束，返回主界面按钮启用
        }

    }
    public static void fallingJudge(JLabel jlabel,Socket socket) {

        timer = new Timer();
        timer.schedule(new TimerTask() {
            @Override
            public void run() {
                jlabel.setLocation(jlabel.getX(), jlabel.getY()+Integer.parseInt(fallSpeed.getText()));
                if(jlabel.getY()>950){
                    mark -=1;
                    labelRight.setText("超时！正确答案："+WordController.rightAnswer);
                    WordController.addWrongWord(false);
                    ButtonController.buttonSetUnable();
                    try {
                        markChange(socket);
                    } catch (InterruptedException | IOException e) {
                        throw new RuntimeException(e);
                    }
                }
            }
        }, Long.parseLong(waitingTime.getText()),10);

    }

    public static void windowInitialization(){//学习窗口初始化
        mark = 10;
        fallingWord.setText("准备开始");
        labelEnd.setText(null);
        labelRight.setText(null);
        labelMark.setText("分数:"+ mark);
        buttonOne.jButton.setText("");
        buttonTwo.jButton.setText("");
        buttonThree.jButton.setText("");
        buttonFour.jButton.setText("");
        WindowController.buttonOne.jButton.setBackground(null);
        WindowController.buttonTwo.jButton.setBackground(null);
        WindowController.buttonThree.jButton.setBackground(null);
        WindowController.buttonFour.jButton.setBackground(null);
        WindowController.buttonOne.jButton.setEnabled(false);
        WindowController.buttonTwo.jButton.setEnabled(false);
        WindowController.buttonThree.jButton.setEnabled(false);
        WindowController.buttonFour.jButton.setEnabled(false);
    }

}
