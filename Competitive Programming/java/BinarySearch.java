public class BinarySearch {

	public static void main(String[] args) {
		int arr[] = {10, 32, 55, 60, 68, 97};
		
		System.out.print("number is in the array: ");
        System.out.println(binarySearch(32, arr));
        
        System.out.print("number is not in the array: ");
        System.out.println(binarySearch(7, arr));
	}

	static boolean binarySearch(int n, int[] arr){
		int middle, left, right;
		left=0; right=arr.length-1;
		while(left <= right){
			middle=(left+right)/2;
			if (n == arr[middle])
                return true;
			if (n < arr[middle])
                right = middle - 1;
			else
				left = middle + 1;
		}
		return false;
	}
	


}