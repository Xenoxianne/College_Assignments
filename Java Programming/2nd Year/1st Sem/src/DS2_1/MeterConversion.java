// Meter to Kilometer

import java.util.Scanner;

public class MeterConversion{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        //Declare variable
        float m, km;

        System.out.println("====== M to KM Conversion ======");

        //User input
        System.out.print("Enter number of meter(s): ");
        m = in.nextFloat();
        in.close();

        //Formula
        km = m/1000;

        //Output
        System.out.println("================================");
        System.out.printf(m + " m = %.2f km", km);
    }
}