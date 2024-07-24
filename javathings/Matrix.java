import java.util.Scanner;
public class Matrix 
{
    public static void main(String[] args)
    {
        Scanner new1=new Scanner(System.in);
        System.out.print("enter the number of rows for the first matrix:");
        int row1=new1.nextInt();
        System.out.print("enter the number of columns for the first matrix:");
        int col1=new1.nextInt();
        System.out.print("enter the number of rows for the second matrix:");
        int row2=new1.nextInt();
        System.out.print("enter the number of columns for the second matrix:");
        int col2=new1.nextInt();
        int mat1[][]=new int[row1][col1];
        int mat2[][]=new int[row2][col2];
        int result[][]=new int[row2][col1];
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col1;j++)
            {
               System.out.print("enter the "+ i +" , "+ j+ " , "+"element of matrix1:" );
               mat1[i][j]=new1.nextInt();
            }
            
        }
        for(int i=0;i<row2;i++)
        {
            for(int j=0;j<col2;j++)
            {
               System.out.print("enter the "+ i +" , "+j+" , " + "element of matrix2:" );
               mat2[i][j]=new1.nextInt();
            }
            
        }
        for (int i = 0; i < row1; i++) 
        {
            for (int j = 0; j < col2; j++) 
            {
                for (int k = 0; k < col1; k++)
                {
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        System.out.println("after multiplication:");
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col2;j++)
            {
                System.out.print(result[i][j]+" ");
            } 
            System.out.println();
        }
        new1.close();
    }
}
