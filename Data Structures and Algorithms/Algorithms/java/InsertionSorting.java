/** WAP to perform insertion sorting
 * @author Indrajit Bhattacharjee
 * @date Jan 20,2019
 */

package codes;

public class InsertionSorting {

	public static void main(String[] args) {

		int a[] = { 2, 15, 56, 88, 3, 0, 12 };
		int l = a.length;
		int i, j, temp, key;

		for (i = 1; i < l; i++) {
			key = a[i];
			j = i - 1;
			// This is ascending order code;
			// for descending we just need to change key > a[j] in while loop
			while (j >= 0 && key < a[j]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				j--;
			}

		}

		// Print the sorted array....
		for (i = 0; i < l; i++) {
			System.out.print(a[i] + " ");
		}

	}

}
//OUTPUT
// 0 2 3 12 15 56 88 
