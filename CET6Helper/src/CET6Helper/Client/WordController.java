package CET6Helper.Client;

import java.io.*;
import java.util.Random;

public class WordController {
    public static String theWord;//出现的单词
    public static String[] meanings = new String[4];//四个中文意思
    public static String rightAnswer = null;//四个中文意思中的正确答案
    public static File masterWord = new File("src/CET6Helper/Client/已掌握单词.txt");//方便起见存在Client内当作本地
    public static File notMasterWord = new File("src/CET6Helper/Client/未掌握单词.txt");//方便起见存在Client内当作本地
    public static String[][] masterArray = new String[3000][2];//已掌握单词，用于reviewWindow
    public static String[][] notMasterArray = new String[3000][3];
    public static void getTheWord(BufferedReader reader) throws IOException {//读取服务端传来的单词与中文意思
        theWord = reader.readLine();
        Boolean[] isExist= new Boolean[4];//用于判断第[]个位置是否存在中文意思
        isExist[0]=false;isExist[1]=false;isExist[2]=false;isExist[3]=false;
        Random random = new Random();
        int right = random.nextInt(4);
        isExist[right] = true;
        meanings[right] = reader.readLine();
        rightAnswer = meanings[right];//将正确意思随机放入某个位置
        for(int i=0;i<3;i++){
            int j;
            j = random.nextInt(4);
            if(isExist[j])i--;//如果该位置已存在中文意思，则重新开始这一步
            else {
                meanings[j] = reader.readLine();//读入中文意思
                isExist[j]=true;
            }
        }
    }

    public static void getTheReviewList(){
        //读取“未掌握单词”与“已掌握单词”列表
        try (BufferedReader masterReader= new BufferedReader(new FileReader(masterWord));
             BufferedReader notMasterReader = new BufferedReader(new FileReader(notMasterWord))){
            String collector;
            int i = 0;
            while((collector = masterReader.readLine())!=null) {
                String[] temp = collector.split("\\s+");
                masterArray[i][0] = temp[0];//单词
                masterArray[i][1] = temp[1];//意思
                i++;
            }
            i=0;
            while ((collector = notMasterReader.readLine())!=null) {
                String[] temp = collector.split("\\s+");
                notMasterArray[i][0] = temp[1];//单词
                notMasterArray[i][1] = temp[2];//意思
                notMasterArray[i][2] = temp[0];//原因
                i++;
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    /*
    *
    * 接下来为加入答对单词(addCorrectWord)与未答或答错单词(addWrongWord)
    * 若某已掌握单词被答错或未答，则将其从已掌握单词中删去
    * 若某未掌握单词被答对，则将其从未掌握单词中删去
    *
    */
    public static void addCorrectWord(){
        try (PrintStream stream = new PrintStream(new FileOutputStream(masterWord,true));
             BufferedReader reader = new BufferedReader(new FileReader(masterWord));
             PrintStream wrongStream = new PrintStream(new FileOutputStream(notMasterWord,true));
             BufferedReader wrongReader = new BufferedReader(new FileReader(notMasterWord))){
            if (isExistCorrect(reader)) return;
            boolean isInWrong;
            isInWrong = wrongWordDeleter(wrongStream, wrongReader, false);
            if(!isInWrong){//不在未掌握单词中则加入已掌握单词中
                StringBuilder tempStr;
                tempStr = new StringBuilder(theWord);//格式制作，\t不工整
                while (tempStr.length() < 21) tempStr.append(" ");
                tempStr.append(rightAnswer);
                stream.println(tempStr);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    public static void addWrongWord(boolean isAnswered){
        try(PrintStream stream = new PrintStream(new FileOutputStream(notMasterWord,true));
            BufferedReader reader = new BufferedReader(new FileReader(notMasterWord));
            PrintStream correctStream = new PrintStream(new FileOutputStream(masterWord,true));
            BufferedReader correctReader = new BufferedReader(new FileReader(masterWord))){
            if (isExistWrong(reader)) return;
            boolean isCorrect;//判断是未答还是答错
            isCorrect = correctWordDeleter(correctStream, correctReader, false);
            if(!isCorrect){//不在已掌握单词中则加入未掌握单词中
                StringBuilder tempStr;//刚开始放回答错误/超时的话，文件中比较工整
                if (isAnswered) tempStr = new StringBuilder("回答错误");
                else tempStr = new StringBuilder("回答超时");
                while (tempStr.length() < 21) tempStr.append(" ");
                tempStr.append(theWord);
                while (tempStr.length() < 42) tempStr.append(" ");
                tempStr.append(rightAnswer);
                stream.println(tempStr);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    public static boolean isExistCorrect(BufferedReader reader) throws IOException {//判断是否存在于已掌握单词中
        String temp;
        while ((temp = reader.readLine())!=null){
            String[] word;
            word = temp.split("\\s+");
            if(theWord.equals(word[0])){
                return true;
            }
        }
        return false;
    }
    public static boolean isExistWrong(BufferedReader reader) throws IOException {//判断是否存在于未掌握单词中
        String temp;
        while ((temp = reader.readLine())!=null){
            String[] word;
            word = temp.split("\\s+");
            if(theWord.equals(word[1])){
                return true;
            }
        }
        return false;
    }
    //wrongWordDeleter用于在addCorrectWord中判断是否存在于未掌握单词中，存在则删去
    public static boolean wrongWordDeleter(PrintStream wrongStream, BufferedReader wrongReader, boolean isInWrong) throws IOException {
        int num = 0;
        String[] savedStates = new String[9999];//原因
        String[] savedWords = new String[9999];//单词
        String[] savedMeanings = new String[9999];//意思
        String wrongWord ;
        while((wrongWord = wrongReader.readLine())!=null){
            String[] tempWord = wrongWord.split("\\s+");
            if(tempWord[1].equals(theWord)) {
                isInWrong = true;
                continue;
            }
            savedStates[num] = tempWord[0];
            savedWords[num] = tempWord[1];
            savedMeanings[num] = tempWord[2];
            num++;
        }
        if(isInWrong){//用重写整个文件的方式删去存在的单词
            PrintStream wrongClear = new PrintStream(new FileOutputStream(notMasterWord));
            wrongClear.close();
            for(int i=0;i<num;i++){
                StringBuilder tempStr = new StringBuilder(savedStates[i]);
                while(tempStr.length()<21)tempStr.append(" ");
                tempStr.append(savedWords[i]);
                while (tempStr.length()<42)tempStr.append(" ");
                tempStr.append(savedMeanings[i]);
                wrongStream.println(tempStr);
            }
        }
        return isInWrong;
    }
    //correctWordDeleter用于在addWrongWord中判断是否存在于已掌握单词中，若存在则删去
    public static boolean correctWordDeleter(PrintStream correctStream, BufferedReader correctReader, boolean isCorrect) throws IOException {
        int num = 0;
        String[] savedWords = new String[9999];
        String[] savedMeanings = new String[9999];
        String correctWord ;
        while ((correctWord = correctReader.readLine())!=null){
            String[] tempWord = correctWord.split("\\s+");
            if(tempWord[0].equals(theWord)){
                isCorrect = true;
                continue;
            }
            savedWords[num] = tempWord[0];
            savedMeanings[num] = tempWord[1];
            num++;
        }
        if(isCorrect){//用重写整个文件的方式删去存在的单词
            PrintStream correctClear = new PrintStream(new FileOutputStream(masterWord));
            correctClear.close();
            for(int i=0;i<num;i++){
                StringBuilder tempStr = new StringBuilder(savedWords[i]);
                while(tempStr.length()<21)tempStr.append(" ");
                tempStr.append(savedMeanings[i]);
                correctStream.println(tempStr);
            }
        }
        return isCorrect;
    }
}
