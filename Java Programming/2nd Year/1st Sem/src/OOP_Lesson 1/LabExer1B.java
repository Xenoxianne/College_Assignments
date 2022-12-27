/**
 * Name: Denise Julianne S. Gozum
 * Section: BSCS 2-5
 * LabExer1: B
 */

public class LabExer1B {
    public static void main(String[] args) {
        int n = 5; //number of rows

        //row
        for(int row = 1; row <= n; row++){
            //column
            for(int col = 1; col <= row; col++){
                System.out.print(col);
            }
            System.out.println(); //newline
        }
    }
}
