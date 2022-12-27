/**
 * Name: Denise Julianne S. Gozum
 * Section: BSCS 2-5
 * LabExer: G
 */

public class LabExerG {
    public static void main(String[] args) {
        //row - x, column - y, num to print - x
        for(int x = 3; x >= 1; x--){        //3 rows
            for(int y = 1; y <= x; y++){    //3 cols, dec. each loop
                System.out.print(x);        //print 3 (x) repeatedly and -1 every new line.
            }System.out.println();          //new line
        }
    }
}
