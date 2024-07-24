import java.util.Scanner;
public class factorial
{
    public static void main(String[] args)
    {
        int fact = 1;  
        int i = 1;  
  
        //creating object of Scanner class  
        Scanner sc = new Scanner(System.in);  
  
        //accepting a number from the user  
        System.out.print("Enter a number whose factorial is to be found: ");  
        int num = sc.nextInt();  
          
        //counting the factorial using while loop  
        while( i <= num ){  
            fact = fact * i;   
            i++; //increment i by 1   
        }
        System.out.print("factorial: "+fact);
        sc.close();
    }
    
}        