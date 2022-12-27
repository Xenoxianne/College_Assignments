// Area of a triangle

import java.util.Scanner;

public class AreaTriangle {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        //Declare variable
        float base, height, area;

        System.out.println("== Measuring the area of a triangle == \n");

        //User input
        System.out.print("Enter the base of the triangle: ");
        base = in.nextFloat();
        System.out.print("Enter the height of the triangle: ");
        height = in.nextFloat();
        in.close();

        //Formulas
        area = (base*height)/2;

        //Output
        System.out.println("\n======================================");
        System.out.printf("Area of the triangle: %.2f", area);
    }
}
