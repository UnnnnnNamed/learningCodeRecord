package CET6Helper;

import CET6Helper.Client.MainClient;
import CET6Helper.Server.MainServer;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Thread server = new Thread(()->{
            try {
                MainServer.main(args);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        });
        Thread client = new Thread(()->{
            try {
                MainClient.main(args);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        });
        server.start();
        Thread.sleep(50);
        client.start();//先开启服务端，再开启客户端
    }
}