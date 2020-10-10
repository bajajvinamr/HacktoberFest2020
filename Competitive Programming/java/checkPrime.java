import java.util.*;
public class CheckPrime{
    public  static void  main(String[] args) {
       
       Scanner sc = new Scanner(System.in);
        
        System.out.println("enter a number");
        int n = sc.nextInt();

        boolean isprime = true;
        for(int i=2; i*i<=n;i++){
            if(n%i==0){
                isprime = false;
            break;
            }
        }
        if(n<2){
                isprime = false;
            }
        if(isprime==false){
        System.out.print(n+" is not a Prime Number");
        }else{
        System.out.print(n+" is a Prime Number");
        }
    }
}