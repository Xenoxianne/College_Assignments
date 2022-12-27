/**
 * Name: Denise Julianne S. Gozum
 * Section: BSCS 2-5
 * LabExer: D
 */

public class LabExerD {
    public static void main(String[] args) {
        //row - x, column - y, num to print - y
        for(int x = 1; x <= 3; x++){    //3 rows
            for(int y = 1, z = 3; y <= x; y++, z--){ //start w/ 1 col, inc each loop
                System.out.print(z);    //print 3 (z) and -1 each loop
            }System.out.println();      //new line
        }
    }
}
