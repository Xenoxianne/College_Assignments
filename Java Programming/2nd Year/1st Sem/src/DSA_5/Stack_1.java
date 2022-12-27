/*
* Gozum, Denise Julianne S.
* BSCS 2-5
* Input elements in the stack until 'z' is entered
* IDE: VSCode
*/

import java.util.Stack;
import java.util.Scanner;

public class Stack_1 {

    /**Push items in a stack */
    private static void pushStack(Stack<Character> st, char val){
        st.push(val);
    }

    /**Show stored items in a stack */
    private static void showStack(Stack<Character> st){
        System.out.println("===========================================================");
        if(st.isEmpty()){
            System.out.println("Stack is empty");   //Empty stack
        }else{
            System.out.println("Stack: " + st);
        }
    }

    public static void main(String[] args) {
        char ans = 'Y';
        Scanner scan = new Scanner(System.in);

        do{
            System.out.println("\033[H\033[2J"); //Clear Screen
            //Initialization and Declaration
            Stack<Character> st = new Stack<Character>();
            char value = 'a'; int n = 0;

            System.out.println("===========================================================");
            System.out.println("                 arr ELEMENTS IN A STACK ");
            System.out.println("===========================================================");
            System.out.println("Enter any character to push in the stack. Enter \'Z\' to exit.");

            while(true){
                //User input
                if(value == 'z' || value == 'Z'){
                    break; //If character input is Z
                }else{
                    System.out.print("  - Enter char " + (n+=1) + ": ");
                    value = scan.next().charAt(0);
                    pushStack(st, value);                 //Push char to the stack
                }
            }
            showStack(st);  //print out values stored in the stack
            System.out.println("===========================================================");

            //Repeat program
            System.out.print("Do you want to try again? (Y/N): ");
            ans = scan.next().charAt(0);
        }while(ans == 'Y' || ans == 'y');

        System.out.println("===========================================================");
        System.out.println("                        THANK YOU ");
        System.out.println("===========================================================");
        
        scan.close();
    }  
}
