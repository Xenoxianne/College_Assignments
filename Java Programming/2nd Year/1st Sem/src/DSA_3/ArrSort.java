/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 2-5
* Sort array in ascending order
*/

import java.util.Scanner;

public class ArrSort {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n, temp, i;
        char ans = 'Y'; //Loop

        do{
            System.out.println("\033[H\033[2J"); //Clear Screen
            System.out.println("==========================================================");
            System.out.println("                  SORT ARRAY ELEMENTS ");
            System.out.println("==========================================================");

            //Enter size of an array
            System.out.print("Input the size of array: ");
            n = scan.nextInt();

            int arr[] = new int[n]; //array initialization

            //Enter elements in array
            System.out.println("\nInput " + n + " elements in the array: ");
            for(i = 0; i < n; i++){
                System.out.print("  - element - " + i + ": ");
                arr[i] = scan.nextInt();
            }

            //Sort Array
            for(i = 0; i < arr.length; i++){ //Traverse through the array
                for(int j = i+1; j < arr.length; j++){ //Check next value
                    if(arr[i] > arr[j]){
                        temp = arr[i];      //copy current value
                        arr[i] = arr[j];    //store checked value to current index
                        arr[j] = temp;      //replace next index w/ temp value
                    }
                }
            }

            //Print out array values
            System.out.println("\nElements of array in sorted ascending order: ");
            for(i = 0; i < arr.length; i++){
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