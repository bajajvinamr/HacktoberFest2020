import java.io.*;
import java.util.*;

//Improvized QuickSort Algorithm so that it works fast even on sequences conatining equal elements.

public class Sorting {
    private static Random random = new Random();
//Code by Nehansh
public static int partition(int start_idx, int finish_idx, int[] a){
        if(a.length == 0){
            //Sometimes you might get an array with length 0;
            return -1;
        }
        if(a.length == 1){
            //Cathes exception if a length is one
            return start_idx;
        }
        int beg_idx = start_idx +1;
        int end_idx = finish_idx;

        while (end_idx > beg_idx) {
            //Begining index goes on until there is a number bigger than starting value
            for (; beg_idx < end_idx && a[beg_idx] <= a[start_idx]; beg_idx++) {
            }  
            //Ending index goes on until there is a number smaller than starting value
            for (; beg_idx < end_idx && a[end_idx] > a[start_idx]; end_idx--) {
            }


            //Once both values are found, a swap happens
            int temp = a[beg_idx];
            a[beg_idx] = a[end_idx];
            a[end_idx] = temp;
        }



        //Swap that happens at the end
        if(a[beg_idx] < a[start_idx]){
            int temp = a[beg_idx];
            a[beg_idx] = a[start_idx];
            a[start_idx] = temp;
            return beg_idx;
        }
        int temp = a[beg_idx-1];
        a[beg_idx-1] = a[start_idx];
        a[start_idx] = temp; 
        return beg_idx-1;
        
    }

    public static void quicksort(int start_idx, int finish_idx, int[] a){
        if(finish_idx - start_idx < 1 || start_idx < 0 ||finish_idx >= a.length){
            return;
        }
        
        //Find the partiton index
        int part = partition(start_idx, finish_idx, a);
		
		int partx = part;
		
		
		while(part>0 && a[part-1]==a[part]){
			part--;
			}
		while(part<a.length && a[part]==a[part+1]){
			partx++;
			}
		

        //partition both sides of the array
        quicksort(start_idx, part-1, a);
        quicksort(partx+1, finish_idx, a);
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
       // randomizedQuickSort(a, 0, n - 1);
       quicksort(0,n-1,a);
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream stream) {
            try {
                br = new BufferedReader(new InputStreamReader(stream));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}

