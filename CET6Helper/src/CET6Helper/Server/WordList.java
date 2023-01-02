package CET6Helper.Server;

import java.io.*;
import java.util.List;
import java.util.Random;

public class WordList {
    static int CNT = 0;//备选单词个数
    public static void listLoader(File file, List<String> eList,List<String> cList){
        try {
            BufferedReader listReader = new BufferedReader(new FileReader(file));
            String flag;
            while ((flag=listReader.readLine())!=null){
                String[] word;
                word = flag.split("\\s+");
                eList.add(word[0]);
                cList.add(word[1]);
                CNT++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void wordOutput(PrintStream stream,List<String> eList,List<String> cList){//输出单词和中文到客户端
        int[] num = new int[4];
        int i = 0;
        while (i < 4){
            Random random = new Random();
            num[i] = random.nextInt(CNT);
            for(int j=0;j<i;j++){
                if(num[j]==num[i]){
                    i--;
                    break;
                }
            }
            i++;
        }
        stream.println(eList.get(num[0]));
        for(int j=0;j<4;j++){
            stream.println(cList.get(num[j]));
        }
    }
}

