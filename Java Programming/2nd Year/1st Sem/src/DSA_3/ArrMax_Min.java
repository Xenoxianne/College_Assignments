/*
* Name: Denise Julianne S. Gozum
* Section: BSCS 2-5
* Min and max element in an array
*/

import java.util.Scanner;

public class ArrMax_Min {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n, min, max;
        char ans = 'Y'; //Loop

        do{
            System.out.println("\033[H\033[2J"); //Clear Screen
            System.out.println("==========================================================");
            System.out.println("                ARRAY MAX AND MIN ELEMENTS ");
            System.out.println("==========================================================");

            //Enter size of an array
            System.out.print("Input the number of elements to be stored in the array: ");
            n = scan.nextInt();

            int arr[] = new int[n]; //array initialization

            //Enter elements in array
            System.out.println("\nInput " + n + " elements in the array: ");
            for(int i = 0; i < n; i++){
                System.out.print("  - element - " + i + ": ");
                arr[i] = scan.nextInt();
            }

            //Get min and max element
            max = arr[0]; min = arr[0];
            for(int j = 0; j < arr.length; j++){
                if(max < arr[j]){   //Get max element
                    max = arr[j];  
                }
                if(min > arr[j]){   //Get min element
                    min = arr[j];
                }
            }
            System.out.println("\nMaximum element is: " + max);
            System.out.println("Minimum element is: " + min);

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