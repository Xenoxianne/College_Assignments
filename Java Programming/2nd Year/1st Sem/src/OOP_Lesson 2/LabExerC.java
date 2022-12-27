/**
 * Name: Denise Julianne S. Gozum
 * Section: BSCS 2-5
 * LabExer: C
 */

public class LabExerC {
    public static void main(String[] args) {
        //row - x, column - y, num to print - y
        for(int x = 3; x >= 1; x--){    //3 rows
            for(int y = 1, z = x; y <= x; y++, z--){    //start w/ 3 cols, dec. each loop
                System.out.print(z);    //print 3 (z), -1 each loop and -1 each new line
            }System.out.println();      //new line
        }
    }
}
