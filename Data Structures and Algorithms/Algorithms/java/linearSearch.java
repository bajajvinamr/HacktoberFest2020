package college;

public class linearSearch {

	public static void main(String[] args) {
		int ar[] = {1,2,5,8,12,27, 31,42};
		int element = 27;
		int ans = linearSearch(ar, 0, 7, element);
		if (ans!=-1)
				System.out.println("element found at "+ans);
		else
			System.out.println("not found");
	}
	static int linearSearch(int [] ar, int start, int end, int element) {
        if (end < start) 
           return -1; 
        if (ar[start] == element) 
           return start; 
        if (ar[end] == element) 
           return end; 
        return linearSearch(ar, start+1, end-1, element); 
	}
}
