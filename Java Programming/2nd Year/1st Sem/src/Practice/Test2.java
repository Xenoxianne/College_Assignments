import java.util.Scanner;

public class Test2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String exp, temp;

        /** User input */
        System.out.println("Enter infix expression: ");
        exp = scan.nextLine();
        exp = exp.replace("(", ")");
        temp = exp.replace(")", "(");
        //StringBuilder output = new StringBuilder(expression);
        //in = output.reverse().toString();

        System.out.println("==============================================");
        System.out.println("Infix expression:\n   " + temp);
    }
}
