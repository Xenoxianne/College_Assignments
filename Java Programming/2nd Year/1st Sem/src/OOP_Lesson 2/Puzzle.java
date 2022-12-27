public class Puzzle{
    public static void main(String[] args) {
        int x,y;
        for (x=1; x<=3;x++){ //outer loop
            for(y=1;y<=x;y++){ // inner loop
                System.out.print(x);
            }
            System.out.println();
        }
    }
}