// Merchandise value

import java.util.Scanner;

    public class MerchValue {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        //Declare variable
        float origPrice, salValue, dep;
        int yrLife, rateDep;

        System.out.println("========= Merchandise Value =========");

        //User input
        System.out.println("Enter the ff. merchandise information ");
        System.out.print("- Original Price: ");
        origPrice = in.nextFloat();
        System.out.print("- Salvage Value: ");
        salValue = in.nextFloat();
        System.out.print("- Year Life: ");
        yrLife = in.nextInt();
        in.close();
        
        //Formula
        dep = (origPrice-salValue)/yrLife;
        rateDep = Math.round((dep/origPrice)*100);

        //Output
        System.out.println("=====================================");
        System.out.printf("Depreciation Value: %.2f\n", dep);
        System.out.println("Rate of Depreciation: " + rateDep + "%");
    }
}
