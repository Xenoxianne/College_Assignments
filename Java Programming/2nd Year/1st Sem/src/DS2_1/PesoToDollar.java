// Peso to dollar

import java.util.Scanner;

public class PesoToDollar {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        //Declare variable
        float peso, dollar;

        System.out.println("==== Peso to Dollar Conversion ====");

        //User input
        System.out.print("Enter Peso amount: ");
        peso = in.nextFloat();
        in.close();

        //Formula
        dollar = (float)(peso/41.25);

        //Output
        System.out.println("===================================");
        System.out.printf(peso + " peso(s) = %.2f dollar(s)", dollar);

    }
}
