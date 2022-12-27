/**
 * Name: Denise Julianne S. Gozum
 * Section: BSCS 2-5
 * LabExer: F
 */

public class LabExerF {
    public static void main(String[] args) {
        //row - x, column - y, num to print - z
        for(int x = 1, z=3; x <= 3; x++, z--){  //3 rows
            for(int y = 1; y <= x; y++){        //1 cols, inc. each loop
                System.out.print(z);            //print 3 (z) repeatedly and -1 every new line.
            }System.out.println();              //new line
        }
    }
}
