/**
 * Name: Denise Julianne S. Gozum
 * Section: BSCS 2-5
 * LabExer: B
 */

public class LabExerB {
    public static void main(String[] args) {
        //row - x, column - y, num to print - z
        for(int x = 3; x >= 1; x--){    //3 rows
            for(int y = 1, z = 3; y <= x; y++, z--){    //start w/ 3 cols, dec. each loop.
                System.out.print(z);    //print 3 (z) and -1 each loop
            }System.out.println();
        }
    }
}
