public class DiagonalSum {
    public int diagonalSum(int[][] mat) 
    {
        int sum = 0;
        for(int i = 0;i < mat.length;i++)
        {
            for(int j = 0;j<mat[i].length;j++)
            {
                if((i==j)||(i+j == mat.length-1))
                   {
                    sum = sum + mat[i][j];   
                   }
            }
        }
        return sum;
        
    }
    public static void main(String args[])
    {
        int mat[][] = new int[][]{{1,2,3},{4,5,6},{7,8,9}};
        DiagonalSum ds = new DiagonalSum();
        int result = ds.diagonalSum(mat);
        System.out.println(result);
    }
    
}
