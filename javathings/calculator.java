import java.util.Scanner;

public class calculator {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            // Input numbers
            System.out.println("Enter first number:");
            double num1 = scanner.nextDouble();

            System.out.println("Enter second number:");
            double num2 = scanner.nextDouble();

            // Input operator
            System.out.println("Enter an operator (+, -, *, /):");
            char operator = scanner.next().charAt(0);

            double result = 0;

            // Perform the operation
            switch (operator) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 == 0) {
                        throw new ArithmeticException("Division by zero is not allowed.");
                    }
                    result = num1 / num2;
                    break;
                default:
                    throw new IllegalArgumentException("Invalid operator. Use +, -, *, or /.");
            }

            // Print the result
            System.out.println("The result is: " + result);

        } catch (ArithmeticException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("An unexpected error occurred: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
