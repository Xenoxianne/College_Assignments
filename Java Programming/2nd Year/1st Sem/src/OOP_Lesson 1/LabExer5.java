/**
 * Name: Denise Julianne S. Gozum
 * Section: BSCS 2-5
 * LabExer5
 */

import java.util.Scanner; //Scanner library 

public class LabExer5 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        //user input
        System.out.print("Given : ");
        int min = input.nextInt();

        int hrs = min / 60; //convert mins to hours
        min = min % 60; //convert remainder to mins

        System.out.printf("Converted hours : %d hours and %d minute/s", hrs, min);
        
        input.close(); //close scanner
    }
}
