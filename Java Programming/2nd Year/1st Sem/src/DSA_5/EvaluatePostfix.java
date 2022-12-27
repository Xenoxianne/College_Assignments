import java.util.Scanner;
import java.util.Stack;
import java.lang.Math;

public class EvaluatePostfix {
    
    public static void main(String[] args) {

        /** Initialization and Declaration */
        Scanner scan = new Scanner(System.in);
        String expression;
        Stack<Double> eval = new Stack<Double>();

        System.out.println("==============================================");
        System.out.println("        EVALUATE THE POSTFIX EXPRESSION       ");
        System.out.println("==============================================");

        /** User input */
        System.out.println("Enter the postfix expression: ");
        expression = scan.nextLine();

        /** Functionality */
        for(int i = 0; i < expression.length(); i++){
            char op = expression.charAt(i);
            if(Character.isDigit(op)){
                eval.push((double) op - '0');
            }else if(op == ' '){
                continue;
            }else{
                double first = eval.pop(), second = eval.pop();
                switch(op){
                    case '^':
                       eval.push(Math.pow(second, first));
                    break;
    
                    case '/':
                        eval.push(second / first);
                    break;
    
                    case '*':
                        eval.push(second * first);
                    break;
    
                    case '-':
                        eval.push(second - first);
                    break;
    
                    case '+':
                        eval.push(second + first);
                    break;
                }
            }
        }
        System.out.println("==============================================");
        System.out.println("Expression: " + expression + "\nEvaluation: " + eval.pop());
        System.out.println("==============================================");
        scan.close();
    }
}
