/*
* Gozum, Denise Julianne S.
* BSCS 2-5
* Infix to Prefix
* IDE: VSCode
*/

import java.util.Scanner;
import java.util.Stack;

public class InfixToPrefix {

    static StringBuilder output = new StringBuilder();

    public static void check(Stack<Character> op, char ex){
        int flag = 0;
        while(flag == 0 && !op.isEmpty()){
            switch(ex){
                case '+': case '-':
                    if(op.peek() == '+' || op.peek() == '-' || op.peek() == '/' || op.peek() == '*' || op.peek() == '^' )
                        output.append(op.pop() + " ");
                    else{
                        op.push(ex); flag = 1;
                    }
                    break;

                case '/': case '*':
                    if(op.peek() == '/' || op.peek() == '*' || op.peek() == '^' )
                        output.append(op.pop() + " ");
                    else{
                        op.push(ex); flag = 1;
                    }
                    break;

                case '^':
                    if(op.peek() == '^' )
                        output.append(op.pop() + " ");
                    else{
                        op.push(ex); flag = 1;
                    }
                    break;
            }
        }
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
        System.out.println("                INFIX TO PREFIX               ");
        System.out.println("==============================================");

        /** User input */
        System.out.println("Enter infix expression: ");
        expression = scan.nextLine();

        System.out.println("==============================================");
        System.out.println("Infix expression:\n   " + expression);
        System.out.print("Prefix expression:\n   ");

        StringBuilder rev = new StringBuilder(expression);
        expression = rev.reverse().toString();

        /** Functionality */
        for(int i = 0; i < expression.length(); i++){
            switch(expression.charAt(i)){
                case ' ':
                    break;  //skip spaces

                case '^': case ')':
                    operator.push(expression.charAt(i));
                    break;

                case '+': case '-': case '*': case '/':
                    check(operator, expression.charAt(i));
                    break;

                case '(':
                    //System.out.println(operator.peek());
                    while(operator.peek() != ')' && !operator.isEmpty()){
                        output.append(operator.pop() + " ");
                    }
                    operator.pop();
                    break;

                default:
                    if((expression.charAt(i) >= 'a' && expression.charAt(i) <= 'z') || (expression.charAt(i) >= 'A' && expression.charAt(i) <= 'Z') || (expression.charAt(i) >= '0' && expression.charAt(i) <= '9'))
                        output.append(expression.charAt(i) + " ");
            }
        }

        while(!operator.isEmpty()){
            output.append(operator.pop() + " ");
        }
        System.out.println(output.reverse());
        System.out.println("==============================================");
        scan.close();
    }
}
