import javax.swing.JOptionPane;

import javax.swing.*;

public class Passenger{
    public static void main(String[] args) {
        int pass, dist, fee = 0, ans = 0;

        while(ans == 0){

            pass = Integer.parseInt(JOptionPane.showInputDialog("Passenger Type"));
            dist = Integer.parseInt(JOptionPane.showInputDialog("Distance"));

            if(pass == 1){
                if(dist<=4){
                    fee = 7;
                }else{
                    fee = (dist - 4) + 7;
                }
            }else if(pass == 2){
                if(dist<=4){
                    fee = 9;
                }else{
                    fee = (dist - 4) + 9;
                }
            }else{
                System.out.println("Invalid Input!");
                fee = 0;
                //System.exit(0);
            }

            System.out.println("Total fare: " + fee);

            ans = JOptionPane.showConfirmDialog(null, "Try Again? ");
        }
    }
}