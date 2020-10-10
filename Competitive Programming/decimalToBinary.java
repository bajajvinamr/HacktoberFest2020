import java.util.*;

public class decimalToBinary{
    //convert a decimal number to binary without using inbuilt functions
    
    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        
        /*
        *  Using inBuilt Function:
        *     String rep = Integer.toBinaryString(number);
        *      System.out.println(rep);
        */
        
        printBinary(number);
    }
    
    public static void printBinary(int n)
    {
        System.out.print("The binary representation of "+n+" is: ");

        if(n == 0)
            System.out.print("0");
        else
        {
            StringBuilder sb = new StringBuilder();
            
            //if the number is postive ,logical and(&) and right shift 
            //should suffice
            
            if(n>0)
            {
                while(n>0)
                {
                    sb.append(n&1);
                    n = n >> 1;
                }
                System.out.print(sb.reverse().toString());
            }
            
            //if the number is negative,use unsigned right shift where zero 
            //gets appened to the right most place
            else
            {
                while(n!=0)
                {
                    sb.append(n&1);
                    n = n >>> 1;
                }
                System.out.print(sb.reverse().toString());
            }
        }
    }   
}