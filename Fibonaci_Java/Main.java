import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) throws InterruptedException, IOException {
        int upperLimit=1000;
        List<BigInteger> array= Collections.synchronizedList(new ArrayList<BigInteger>(upperLimit+1));
        for(int i=0;i<=upperLimit;i++)
            array.add(i,new BigInteger(String.valueOf(0)));


        ArrayList<Thread>  threads;

        long T1=0;

        double M= 6 * 1.3;

        for(int i=0;i<=20;i++)
        {
            int nr_threads= (int) Math.pow(2,i);

            long timeA = System.currentTimeMillis();

            threads=new ArrayList<Thread>(nr_threads);


          for(int j=0;j<nr_threads;j++)
          {
               threads.add(j,new Thread(new FibonaciComputer(array,nr_threads,upperLimit,j)));
               threads.get(j).start();


          }
            for(int j=0;j<nr_threads;j++)
            {
              threads.get(j).join();

            }
            long timeB = System.currentTimeMillis();
            long executionTime=timeB-timeA;

            if(i==0)
              T1=executionTime;
        if(executionTime!=0) {
            double speedup = (double) ((double)T1 / executionTime);
            double efficiency = (double) speedup / M;

            System.out.println("For " + nr_threads + " threads execution is:"+executionTime+" ms Speedup is:" + speedup + " efficency is:" + efficiency);
        }

        }
        File myObj = new File("Fibonaci.txt");
        FileWriter myWriter = new FileWriter("Fibonaci.txt");
        for(int i=0;i<=upperLimit;i+=1)
        {
            myWriter.write("F("+i+")="+array.get(i)+"\n");
            System.out.println(i);

        }
        myWriter.close();
        System.out.println("Hello world!");
    }
}