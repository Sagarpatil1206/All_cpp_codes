import java.io.*;
class nam{
    public static void main(String args[])throws IOException{
        FileWriter fw=new FileWriter("write.txt");
        FileReader fr=new FileReader("File.txt");
        BufferedReader br=new BufferedReader(fr);
        BufferedWriter bw=new BufferedWriter(fw);
        bw.write("today si sunny");
        bw.close();
        System.out.println("Sucess");
    }
}