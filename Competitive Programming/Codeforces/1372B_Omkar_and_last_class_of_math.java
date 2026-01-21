import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 
import java.util.*;
  
public class om_math_kar
{ 
    //By shwetank_verma
    static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 
    static int mod=1000000007;
    static boolean primes[]=new boolean[1000007];
    static ArrayList<Integer> l=new ArrayList<>();
    static void seive(int n){
        Arrays.fill(primes,true);
        primes[0]=primes[1]=false;
        for(int i=2;i*i<=n;i++){
            if(primes[i]==true){
                for(int p=i*i;p<=n;p+=i){
                    primes[p]=false;
                }
            }
        }
        for(int i=0;i<n;i++) {
        	if(primes[i])
        		l.add(i);
        }
       
        
    }
    static int gcd(int a,int b){
        if(b==0)
        return a;
        return gcd(b,a%b);
    }
    static long GCD(long a,long b){
        if(b==0)
        return a;
        return GCD(b,a%b);
    }
    
  
    public static void main(String[] args) 
    { 
        FastReader sc=new FastReader(); 
        try{
           
        	    
                int t=sc.nextInt();
                while(t-->0){
                int n=sc.nextInt();
                int max=0;
                ArrayList<Integer> p=new ArrayList<Integer>();
                for(int i=1;i*i<=n;i++) {
                	if(n%i==0) {
                		p.add(i);
                		if(i*i!=n)
                			p.add(n/i);
                	}
                }
                Collections.sort(p);
                
                max=p.get(p.size()-2);
                
                System.out.println(max+" "+(n-max));
        
                }
           
            
        }catch(Exception e){
            return;
        }
    } 
}
