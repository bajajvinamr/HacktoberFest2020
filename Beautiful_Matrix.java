import java.util.*;
public class Beautiful_Matrix {
    static Scanner sr = new Scanner(System.in);
    public static void main(String args[])
    {
        int i=0,j=0,row=0,col=0,count=0;
        int arr[][] = new int[5][5];
        String str = null;
        String[] a = new String[5];
        for(i=0;i<5;i++)
        {
            str = sr.nextLine();
            str.trim();
            a = str.split(" ");
            for(j=0;j<5;j++)
            {
                arr[i][j] = Integer.parseInt(a[j]);
            }
        }
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(arr[i][j] == 1)
                {
                    row = i+1;
                    col = j+1;
                    break;
                }
            }
        }
        while(row!=3)
        {
            if(row>3)
            {
                row--;
                count++;
            }
            else
            {
                row++;
                count++;
            }
        }
        while(col!=3)
        {
            if(col>3)
            {
                col--;
                count++;
            }
            else
            {
                col++;
                count++;
            }
        }
        System.out.println(count);
    }
}
