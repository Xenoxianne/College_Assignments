/*
* Gozum, Denise Julianne S.
* BSCS 2-5
* Complete the parenthesis and evaluate the expression
* IDE: VSCode
*/

import java.util.EmptyStackException;
import java.util.Stack;
import java.util.Scanner;
import java.lang.Math;

public class Stack_5{
    
    public static void main(String[] args) {
        /** Initialization and Declaration */
        Scanner scan = new Scanner(System.in);

        //for operator
        Stack<Character> operator = new Stack<Character>();
        char op;

        //for completng the expression
        Stack<String> operand = new Stack<String>();
        String check, first, second;

        //for evaluation                  
        double firstD, secondD;
        Stack<Double> operandD = new Stack<Double>();

        System.out.println("==============================================");
        System.out.println("            EVALUATE THE EXPRESSION           ");
        System.out.println("==============================================");

        /** User input */
        System.out.println("Expression to fix:");
        check = scan.nextLine();
        System.out.println("==============================================");

        System.out.println("Original expression:\n   " + check);

        /** Functionality */
        //check expression 1 by 1
        for(int i = 0; i < check.length(); i++){

            switch(check.charAt(i)){
                case '+': case '-': case '*': case '/': case '^':
                    operator.push(check.charAt(i));
                    break;

                case '1': case '2': case '3': case '4': case '5': 
                case '6': case '7': case '8': case '9': case '0':
                    //Complete expression
                    String num = "" + check.charAt(i);  //convert char to string
                    operand.push(num);
                    
                    //Evaluate expression
                    double numD = (double) check.charAt(i) - '0';  //convert char to int
                    operandD.push(numD);

                    break;

                case ')':
                    op = operator.pop();

                    //Complete expression
                    first = operand.pop();  
                    second = operand.pop();

                    StringBuilder buildStr = new StringBuilder();       //for appending strings
                    buildStr.append("( " + second + " " + op + " " + first + " " + ")");

                    operand.push(buildStr.toString());  //push appended string (fix expression) to operand
                    
                    //Evaluate expression
                    firstD = operandD.pop();  
                    secondD = operandD.pop();

                    if(op == '+')   operandD.push(secondD + firstD);
                    else if(op == '-') operandD.push(secondD - firstD);
                    else if(op == '*') operandD.push(secondD * firstD);
                    else if(op == '/') operandD.push(secondD / firstD);
                    else if(op == '^') operandD.push(Math.pow(secondD, firstD));

                    break;

                case ' ':
                    break;  //skip spaces
            }
        }
        
        try{
            System.out.println("Completed expression\n   " + operand.pop());
            System.out.println("Evaluated expression: " + operandD.pop());
        }catch(EmptyStackException e){
            System.out.println("Stack is empty");   //catch empty stack
        }
        
        System.out.println("==============================================");
        scan.close();
    }
}