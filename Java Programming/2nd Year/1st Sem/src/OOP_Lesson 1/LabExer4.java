/**
 * Name: Denise Julianne S. Gozum
 * Section: BSCS 2-5
 * LabExer4
 */

import java.util.Scanner; //Scanner library 

public class LabExer4 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); //used to take user input
        double rate, hrs, grossPay, tax, netPay;

        //Hourly rate
        System.out.print("Hourly rate : ");
        rate = input.nextDouble(); //store user input in variable rate

        //Hours worked
        System.out.print("Hours worked : ");
        hrs = input.nextDouble(); //store user input in variable hrs

        //Gross pay 
        grossPay = rate * hrs;
        //without string format
        System.out.println("Gross pay : " + grossPay); 

        //Withholding tax (15%)
        tax = grossPay * 0.15;
        //string format to print up to 3 decimal places
        System.out.println("Withholding tax :" + String.format("%.3f", tax)); 

        //Net pay
        netPay = grossPay - tax;
        //string format printf method to print up to 3 decimal places
        System.out.printf("Net pay : %.3f", netPay); 

        input.close();
    }
}
