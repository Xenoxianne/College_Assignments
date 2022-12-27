import java.util.Scanner;

public class prac2{
    public static void main(String [] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Hello: ");
        String name = scan.nextLine();

        System.out.println("Your name is " + name);

        scan.close();
    }
}