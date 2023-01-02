package CET6Helper.Client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

import static CET6Helper.Client.WindowController.readyTime;

public class MainClient {
    public static void main(String[] args) throws IOException {
        try(Socket socket = new Socket("localhost",8080)){
            clientAction(socket);
        } catch (IOException | InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

    private static void clientAction(Socket socket) throws IOException, InterruptedException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        if(!WordController.masterWord.exists()) WordController.masterWord.createNewFile();
        if(!WordController.notMasterWord.exists()) WordController.notMasterWord.createNewFile();
        WindowController.creatWindow(socket);
        ButtonController.buttonSetUnable();
        WindowController.buttonBackToMain.jButton.setEnabled(false);

        while (true){
            WordController.getTheWord(reader);//从流中读取服务端发出的单词与中文意思
            WindowController.fallingWord.setLocation(150,75);//单词复位
            Thread.sleep(Long.parseLong(readyTime.getText()));//每题显示前休眠readyTime秒

            ButtonController.buttonSetter(WindowController.fallingWord,WindowController.buttonOne, WindowController.buttonTwo
                                         ,WindowController.buttonThree,WindowController.buttonFour);//按钮text设置中文意思

            WindowController.fallingJudge(WindowController.fallingWord, socket);//单词开始掉落
            ButtonController.buttonSetEnabled();//答题开始
        }

    }
}
