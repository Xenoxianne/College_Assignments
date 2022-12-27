/**
 * Name: Denise Julianne S. Gozum
 * Section: BSCS 2-5
 * LabExer6
 */

import java.util.Scanner; //Scanner library 

public class LabExer6 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); //used to take user input
        int p1000 = 0, p500 = 0, p100 = 0, p50 = 0, p20 = 0, p10 = 0, p5 = 0, p1 = 0, cash;

        System.out.print("Cash on hand : ");
        cash = input.nextInt(); //take cash

        System.out.println("Denominations :");

        //PHP 1000
        if(cash >= 1000){
            p1000 = cash / 1000; //divide by one 1000 peso bill
            cash -= p1000 * 1000; //minus number of bills possible to original cash
        } 
        //PHP 500
        if(cash >= 500){
            p500 = cash / 500;
            cash -= p500 * 500;
        } 
        //PHP 100
        if(cash >= 100){
            p100 = cash / 100;
            cash -= p100 * 100;
        } 
        //PHP 50
        if(cash >= 50){
            p50 = cash / 50;
            cash -= p50 * 50;
        } 
        //PHP 20
        if(cash >= 20){
            p20 = cash / 20;
            cash -= p20 * 20;
        } 
        //PHP 10
        if(cash >= 10){
            p10 = cash / 10;
            cash -= p10 * 10;
        } 
        //PHP 5
        if(cash >= 5){
            p5 = cash / 5;
            cash -= p5 * 5;
        } 
        //PHP 1
        if(cash >= 1){
            p1 = cash / 1;
            cash -= p1 * 1;
        }

        System.out.println("1000 - " + p1000); 
        System.out.println("500 - " + p500);
        System.out.println("100 - " + p100);
        System.out.println("50 - " + p50);
        System.out.println("20 - " + p20);
        System.out.println("10 - " + p10);
        System.out.println("5 - " + p5);
        System.out.println("1 - " + p1);

        input.close(); //close scanner
    }
}
