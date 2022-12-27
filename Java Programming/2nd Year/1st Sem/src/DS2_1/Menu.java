import java.util.Scanner;

public class Menu {
    
    static Scanner in = new Scanner(System.in);
    static char FuncRep = 'N'; //repeat program
    public static void main(String[] args) {
        int ans;
        char exit = 'N'; //exit menu
        
        while(exit == 'N' || exit == 'n'){
            FuncRep = 'N';
            System.out.print("\033[H\033[2J");
            System.out.println("====================================");
            System.out.println("            ASSIGNMENT #2           ");
            System.out.println("====================================");
            System.out.println("[1] Area of a Triangle\n[2] Merchandise Value\n[3] Meter to Kilometer Conversion\n[4] Peso to Dollar Conversion\n[5] Perimeter and Area of a Square\n[6] Exit");
            System.out.println("------------------------------------");
            System.out.print("- Choose a program [1-6]: ");
            ans = in.nextInt();
            switch (ans) {
                case 1: AreaTriangle(); break;      //Area of a Triangle
                case 2: MerchValue(); break;        //Merchandise Value
                case 3: MeterConversion(); break;   //Meter to KM Conversion
                case 4: PesoToDollar(); break;      //Pesos to Dollar Conversion
                case 5: SquareSide(); break;        //Area and Perimeter of a Square
                case 6: System.out.println("====================================");
                        System.out.print("Are you sure you want to exit? (Y/N): ");
                        exit = in.next().charAt(0);
                        break;
                default: System.out.println("===================================="); 
                         System.out.println("       Error! Incorrect Value!"); exit = 'Y'; 
                         System.out.println("====================================");
                         System.out.print("Try again? (Y/N): ");
                         exit = in.next().charAt(0);
                         if(exit == 'Y' || exit == 'y') exit = 'N';
                         else System.exit(0);
                        break;
            }
        }
        System.out.println("====================================");
        System.out.println("          HAVE A GREAT DAY!         ");
        System.out.println("====================================");
        in.close();   
    }
    
    //Area of a Triangle
    public static void AreaTriangle(){
        float base, height, area;

        while(FuncRep == 'N' || FuncRep == 'n'){
            System.out.print("\033[H\033[2J"); //clear screen
            System.out.println("== Measuring the area of a triangle == \n");

            //User input
            System.out.print("Enter the base of the triangle: ");
            base = in.nextFloat();
            System.out.print("Enter the height of the triangle: ");
            height = in.nextFloat();

            //Formulas
            area = (base*height)/2;

            //Output
            System.out.println("\n--------------------------------------");
            System.out.printf("Area of the triangle: %.2f", area);
            System.out.println("\n======================================");
            System.out.print("\nExit to main menu? ");
            FuncRep = in.next().charAt(0);
        }
    }

    //Merchandise Value
    public static void MerchValue(){
        //Declare variable
        float origPrice, salValue, dep;
        int yrLife, rateDep;

        while(FuncRep == 'N' || FuncRep == 'n'){
            System.out.print("\033[H\033[2J"); //clear screen
            System.out.println("========= Merchandise Value =========");

            //User input
            System.out.println("Enter the ff. merchandise information ");
            System.out.print("- Original Price: ");
            origPrice = in.nextFloat();
            System.out.print("- Salvage Value: ");
            salValue = in.nextFloat();
            System.out.print("- Year Life: ");
            yrLife = in.nextInt();
            
            //Formula
            dep = (origPrice-salValue)/yrLife;
            rateDep = Math.round((dep/origPrice)*100);

            //Output
            System.out.println("--------------------------------------");
            System.out.printf("Depreciation Value: %.2f\n", dep);
            System.out.println("Rate of Depreciation: " + rateDep + "%");
            System.out.println("======================================");
            System.out.print("Exit to main menu? ");
            FuncRep = in.next().charAt(0);
        }
    }

    //Meter to KM Conversion
    public static void MeterConversion(){
        //Declare variable
        float m, km;

        while(FuncRep == 'N' || FuncRep == 'n'){
            System.out.print("\033[H\033[2J"); //clear screen
            System.out.println("====== M to KM Conversion ======");

            //User input
            System.out.print("Enter number of meter(s): ");
            m = in.nextFloat();

            //Formula
            km = m/1000;

            //Output
            System.out.println("================================");
            System.out.printf(m + " m = %.2f km", km);
            System.out.println("\n================================");
            System.out.print("Exit to main menu? ");
            FuncRep = in.next().charAt(0);
        }
    }

    //Pesos to Dollar Conversion
    public static void PesoToDollar(){
        //Declare variable
        float peso, dollar;

        while(FuncRep == 'N' || FuncRep == 'n'){
            System.out.print("\033[H\033[2J"); //clear screen
            System.out.println("==== Peso to Dollar Conversion ====");

            //User input
            System.out.print("Enter Peso amount: ");
            peso = in.nextFloat();

            //Formula
            dollar = (float)(peso/41.25);

            //Output
            System.out.println("===================================");
            System.out.printf(peso + " peso(s) = %.2f dollar(s)", dollar);
            System.out.println("\n===================================");
            System.out.print("Exit to main menu? ");
            FuncRep = in.next().charAt(0);
        }
    }

    //Area and Perimeter of a Square
    public static void SquareSide(){
        //Declare variable
        int side, perimeter, area; 

        while(FuncRep == 'N' || FuncRep == 'n'){
            System.out.print("\033[H\033[2J"); //clear screen
            System.out.println("========== Measuring a Square ==========");

            //User input
            System.out.print("Enter side measurement of a square: ");
            side = in.nextInt();

            //Formulas
            perimeter = side * 4;
            area = side * side;

            //Output
            System.out.println("========================================");
            System.out.println("Perimeter of a square: " + perimeter);
            System.out.println("Area of a square: " + area);
            System.out.println("========================================");
            System.out.print("Exit to main menu? ");
            FuncRep = in.next().charAt(0);
        }
    }
}
