// Perimeter and area of a square

import java.util.Scanner;

public class SquareSide{
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        //Declare variable
        int side, perimeter, area; 

        System.out.println("========== Measuring a Square ==========");

        //User input
        System.out.print("Enter side measurement of a square: ");
        side = in.nextInt();
        in.close();

        //Formulas
        perimeter = side * 4;
		area = side * side;

        //Output
        System.out.println("========================================");
        System.out.println("Perimeter of a square: " + perimeter);
        System.out.println("Area of a square: " + area);

    }
}