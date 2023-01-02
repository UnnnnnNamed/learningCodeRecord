package CET6Helper.Server;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;
import java.util.List;

public class MainServer {
    public static void main(String[] args) throws IOException {
        File cetFILE = new File("src/CET6Helper/Server/CET6.txt");//方便起见存在Server内当作服务端
        List<String> englishLIST = new LinkedList<>();
        List<String> chineseLIST = new LinkedList<>();

        try(ServerSocket server = new ServerSocket(8080);
            Socket socket = server.accept()){
            serverAction(cetFILE, englishLIST, chineseLIST, socket);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    private static void serverAction(File cetFILE, List<String> englishLIST, List<String> chineseLIST, Socket socket) throws IOException {
        PrintStream stream = new PrintStream(socket.getOutputStream());
        BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        WordList.listLoader(cetFILE, englishLIST, chineseLIST);
        while (true) {
            String order;
            order = reader.readLine();
            if(order.equals("BEGIN")){//答题开始
                WordList.wordOutput(stream, englishLIST, chineseLIST);
                while (true){
                    order = reader.readLine();
                    if (order.equals("NEXT")) WordList.wordOutput(stream, englishLIST, chineseLIST);//下一题
                    else if(order.equals("BACK")) break;//返回主界面，本次答题结束，等待下一次答题开始的指令
                }
            }
        }
    }

}
