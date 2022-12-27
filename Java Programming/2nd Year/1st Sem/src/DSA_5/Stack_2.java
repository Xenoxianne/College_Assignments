/*
* Gozum, Denise Julianne S.
* BSCS 2-5
* Input elements in the stack until a vowel is entered then print in reverse order
* IDE: VSCode
*/

import java.util.Stack;
import java.util.Scanner;

public class Stack_2 {

    /**Push items in a stack */
    private static void pushStack(Stack<Character> st, char val){
        st.push(val);
    }

    /**Show stored items in a stack */
    private static void showStack(Stack<Character> st){
        if(st.isEmpty()){
            System.out.println("Stack is empty");   //Empty stack
        }else{
            System.out.println("Stack: " + st);
        }
    }

    /**Show and pop stored items in a stack in reverse order*/
    private static void popStack(Stack<Character> st){
        System.out.print("Values in reverse: ");
        do{
            System.out.print(st.pop() + " ");   
        }while(st.isEmpty() != true);
        System.out.println();
    }

    public static void main(String[] args) {
        char ans = 'Y';
        Scanner scan = new Scanner(System.in);

        do{
            System.out.println("\033[H\033[2J"); //Clear Screen
            //Initialization and Declaration
            Stack<Character> st = new Stack<Character>();
            char check = 'w', value = 'a'; int n = 0;

            System.out.println("===========================================================");
            System.out.println("   arr AND PRINT ELEMENTS IN A STACK IN REVERSE ORDER");
            System.out.println("===========================================================");
            System.out.println("Enter any character to push in the stack.\nEnter a vowel to exit.");

            while(true){
                //User input
                if(check == 'A' || check == 'E' || check == 'I' || check == 'O' || check == 'U'){
                    break; //If character input is Z
                }else{
                    System.out.print("  - Enter char " + (n+=1) + ": ");
                    value = scan.next().charAt(0);
                    check = Character.toUpperCase(value); //Change to uppercase for checking
                    pushStack(st, value);                 //Push char to the stack
                }
            }
            
            System.out.println("===========================================================");
            showStack(st);  //print out values stored in the stack
            popStack(st);   //show and pop items stored in the stack
            showStack(st);  //check if item remains in the stack
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
