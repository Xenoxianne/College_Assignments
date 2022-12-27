/*
* Gozum, Denise Julianne S.
* BSCS 2-5
* Infix to Postfix
* IDE: VSCode
*/

import java.util.Scanner;
import java.util.Stack;

public class InfixToPostfix {

    /** Check precedence */
    public static void check(Stack<Character> op, char ex){
        int flag = 0;   //stop loop

        while(flag == 0 && !op.isEmpty()){
            switch(ex){
                case '+': case '-':
                    if(op.peek() == '+' || op.peek() == '-' || op.peek() == '/' || op.peek() == '*' || op.peek() == '^' )
                        System.out.print(op.pop() + " ");
                    else{
                        op.push(ex); flag = 1;
                    }
                    break;

                case '/': case '*':
                    if(op.peek() == '/' || op.peek() == '*' || op.peek() == '^' )
                        System.out.print(op.pop() + " ");
                    else{
                        op.push(ex); flag = 1;
                    }
                    break;

                case '^':
                    if(op.peek() == '^' )
                        System.out.print(op.pop() + " ");
                    else{
                        op.push(ex); flag = 1;
                    }
                    break;
            }
        }

        // Empty stack
        if(op.isEmpty()){
            op.push(ex);
        }
    }

    public static void main(String[] args) {

        /** Initialization and Declaration */
        Scanner scan = new Scanner(System.in);
        String expression;
        Stack<Character> operator = new Stack<Character>();

        System.out.println("==============================================");
        System.out.println("                INFIX TO POSTFIX              ");
        System.out.println("==============================================");

        /** User input */
        System.out.println("Enter infix expression: ");
        expression = scan.nextLine();

        System.out.println("==============================================");
        System.out.println("Infix expression:\n   " + expression);
        System.out.print("Postfix expression:\n   ");

        /** Functionality */
        for(int i = 0; i < expression.length(); i++){
            switch(expression.charAt(i)){
                case ' ':
                    break;  //skip spaces

                case '(':
                    operator.push(expression.charAt(i));
                    break;

                case '+': case '-': case '*': case '/': case '^': 
                    check(operator, expression.charAt(i));
                    break;

                case ')':
                    while(operator.peek() != '(' && !operator.isEmpty()){
                        System.out.print(operator.pop() + " ");
                    }
                    operator.pop();
                    break;

                default:
                    System.out.print(expression.charAt(i) + " ");   //For character operands
            }
        }

        // Remaining operator in the stack
        while(!operator.isEmpty()){
            System.out.print(operator.pop() + " ");
        }

        System.out.println("\n==============================================");
        scan.close();
    }
}