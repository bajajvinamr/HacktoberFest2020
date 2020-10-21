
import java.util.*;
import java.lang.*;
import java.io.*;
public class Hulk {
   
     public static void main(String args[]) throws java.lang.Exception
    {
        int n = 0 , count = 0;
        String hate = "I hate ";
        String love = "I love ";
        String it = "it";
        String that = "that ";
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        try
        {
        n = Integer.parseInt(br.readLine());
        }
        catch(Exception e)
        {
            return; 
        }
        System.out.print(hate);
        
        for(int i = 2 ; i < n+1 ; i++)
        {
            if(i%2 == 0)
            {
                System.out.print(that);
                System.out.print(love);
            }
            else
            {
                System.out.print(that);
                System.out.print(hate);
            }
        }
        
        System.out.print(it);
    }
}