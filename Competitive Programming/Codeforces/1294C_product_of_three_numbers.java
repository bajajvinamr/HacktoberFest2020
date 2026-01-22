import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 
import java.util.*;
  
public class potn
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
    
    static boolean seive(int n){
        Arrays.fill(primes,true);
        primes[0]=primes[1]=false;
        for(int i=2;i*i<=n;i++){
            if(primes[i]==true){
                for(int p=i*i;p<=n;p+=i){
                    primes[p]=false;
                }
            }
        }
        if(n<1000007){
            return primes[n];
        }
        return false;
        
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
                
                ArrayList<Integer> l=new ArrayList<Integer>();
                for(int i=2;i*i<=n;i++) {
                	if(n%i==0) {
                		l.add(i);
                		if(i*i!=n)
                			l.add(n/i);
                	}
                }
                
                long a=0,b=0,c=0;
                boolean ans=false;
                for(int i=0;i<l.size();i++) {
                	a=l.get(i);
                	for(int j=0;j<l.size();j++) {
                		if(i!=j) {
                			b=l.get(j);
                			if(n%(a*b)==0&&n!=a*b) {
                				c=n/(a*b);
                				if(c==1||c==a||c==b)
                					continue;
                				else {
                					ans=true;
                					break;
                				}
                				
                			}
                			
                		}
                	}
                	if(ans)
                		break;
                }
                if(ans)
                {
                	System.out.println("YES");
                	System.out.println(a+" "+b+" "+c);
                }
                else
                	System.out.println("NO");
                }
           
            
        }catch(Exception e){
            return;
        }
    } 
}
