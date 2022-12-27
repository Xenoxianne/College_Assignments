/**
 * Name: Denise Julianne S. Gozum
 * Section: BSCS 2-5
 * LabExer: A
 */

public class LabExerA {
    public static void main(String[] args) {
        //row - x, column - y, num to print - y
        for(int x = 3; x >= 1; x--){        //3 rows
            for(int y = 1; y <= x; y++){    //3 cols, dec. each loop
                System.out.print(y);        //print 1 (y) and +1 every loop.
            }System.out.println();          //new line
        }
    }
}
