import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args)throws IOException {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Stack<Integer> st1=new Stack<>();
        Stack<Integer> st2=new Stack<>();
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int q=Integer.parseInt(br.readLine());
        String[] str=new String[q];
        int c1=0;
        while(q>0)
        {
           
             str[c1]=br.readLine();
            
            
             q--;
             c1++;

        }
        for(int i=0;i<str.length;i++)
        {
               char c=str[i].charAt(0);
               if(c=='1')
               {   int num=Integer.parseInt(str[i].substring(2));  
                   st1.add(num);
               }
        }
        for(int i=0;i<str.length;i++)
        {
            char c=str[i].charAt(0);
            if(c=='2')
            {
                while(!st1.isEmpty())
                {
                    st2.add(st1.pop());
                }
                st2.pop();
            }
            else if(c=='3')
            {
                if(!st1.isEmpty())
                { while(!st1.isEmpty())
                  {
                    st2.add(st1.pop());
                  }
                  System.out.println(st2.peek());
                }
                else
                {
                    System.out.println(st2.peek());
                }
            }
        }
    }
}
