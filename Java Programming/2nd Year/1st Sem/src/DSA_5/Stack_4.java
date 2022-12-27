/*
* Gozum, Denise Julianne S.
* BSCS 2-5
* Complete the parenthesis in the expression
* IDE: VSCode
*/

import java.util.EmptyStackException;
import java.util.Stack;
import java.util.Scanner;

public class Stack_4 {
    public static void main(String[] args) {
        //Initialization and Declaration
        Scanner scan = new Scanner(System.in);
        String check, first, second;
        char op;
        Stack<String> operand = new Stack<String>();
        Stack<Character> operator = new Stack<Character>();

        //Initialization and Declaration
        System.out.println("==============================================");
        System.out.println("              FIX THE EXPRESSION              ");
        System.out.println("==============================================");
        
        //user input
        System.out.println("Expression to fix:");
        check = scan.nextLine();
        System.out.println("==============================================");

        try{
            System.out.println("Original expression:\n   " + check);
            System.out.println("Completed expression");

            //check expression 1 by 1
            for(int i = 0; i < check.length(); i++){
                switch(check.charAt(i)){
                    case '+': case '-': case '*': case '/': case '^':
                        operator.push(check.charAt(i));
                        break;
                    case '1': case '2': case '3': case '4': case '5': 
                    case '6': case '7': case '8': case '9': case '0':
                        String num = "" + check.charAt(i);  //convert char to string
                        operand.push(num);
                        break;
                    case ')':
                        first = operand.pop();  
                        second = operand.pop();
                        op = operator.pop();

                        //for appending strings
                        StringBuilder buildStr = new StringBuilder();
                        buildStr.append("( " + second + " " + op + " " + first + " " + ")");

                        operand.push(buildStr.toString());  //push appended string (fix expression) to operand
                        break;
                    case ' ':
                        break;  //skip spaces
                }
            }
            System.out.println("   " + operand.pop());  //output stack
        }catch(EmptyStackException e){
            System.out.println("Stack is empty");   //catch empty stack
        }
        System.out.println("==============================================");

        scan.close();
    }
}
