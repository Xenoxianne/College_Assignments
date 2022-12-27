/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 2-5
* Delete an element in an array
*/

import java.util.Scanner;

public class ArrDelete {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n, pos, i, j;
        char ans = 'Y'; //Loop

        do{
            System.out.println("\033[H\033[2J"); //Clear Screen
            System.out.println("==========================================================");
            System.out.println("                  DELETE ARRAY ELEMENTS ");
            System.out.println("==========================================================");

            //Enter size of an array
            System.out.print("Input the size of array: ");
            n = scan.nextInt();

            int arr[] = new int[n]; //array initialization

            //Enter elements in array
            System.out.println("\nInput " + n + " elements in the array in ascending order: ");
            for(i = 0; i < n; i++){
                System.out.print("  - element - " + i + ": ");
                arr[i] = scan.nextInt();
            }

            //Get position to delete
            System.out.print("\nInput the position where to delete: ");
            pos = scan.nextInt();

            //Delete and move array elements
            if(arr.length >= pos-1 || pos > 0){
                for(i = pos, j = pos-1; i < arr.length; i++, j++){
                    arr[j] = arr[i];
                }
                n--;
            }

            //Print out array values
            System.out.println("\nThe new list is: ");
            for(i = 0; i < n; i++){
                System.out.print(arr[i] + " ");
            }

            //Loop for repeat hw
            System.out.println("\n----------------------------------------------------------");
            System.out.print("Try Again? (Y/N): ");
            ans = scan.next().charAt(0);
        }while(ans == 'Y' || ans == 'y');

        System.out.println("==========================================================");
        System.out.println("                       THANK YOU ");
        System.out.println("==========================================================");
        scan.close();   //Close scanner
    }
}