/**
 * Name: Denise Julianne S. Gozum
 * Section: BSCS 2-5
 * LabExer1: A
 */

public class LabExer1A{
    public static void main(String[] args) {
        int n = 3; //half number of rows

        //rows 1-3
        for(int row = 1; row <= n; row++){
            //Spaces
            for(int space = 1; space <= (n - row); space++){
                System.out.print(" ");
            }
            //asterisks
            for(int star = 1; star <= (row * 2)-1; star++){
                System.out.print("*");
            }
            System.out.println(); //newline
        } 

        //rows 4-6
        for(int row = n; row > 0; row--){
            for(int space = 1; space <= (n - row); space++){
                System.out.print(" ");
            }
            //asterisks
            for(int star = 1; star <= (row*2)-1; star++){
                System.out.print("*");
            }
            System.out.println(); //newline
        }
    }
}