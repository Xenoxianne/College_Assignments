/*
* Group 1: Besmonte, Gozum, Mendoza, Sison, Suzn
* BSCS 2-5
* Password
*/

import javax.swing.*;

public class Assign3_2 {
    public static void main(String[] args) {
        String pass;
        String access = "";
        int count=0;
        
        //Password creation
        pass = JOptionPane.showInputDialog(null, "Create a password: " , "Sign In", JOptionPane.INFORMATION_MESSAGE);
        JOptionPane.showMessageDialog(null, "Password Created!", "Successful", JOptionPane.PLAIN_MESSAGE);
        //Access Validation
        do{
            access = JOptionPane.showInputDialog(null, "Enter your password: ", "Login", JOptionPane.INFORMATION_MESSAGE);

            if(!access.equals(pass)){
                JOptionPane.showMessageDialog(null, "MALI PASSWORD MO!!!", "Error", JOptionPane.WARNING_MESSAGE);
                count++;
            }else{
                JOptionPane.showMessageDialog(null, "TAMA YAN", "Login Successful", JOptionPane.INFORMATION_MESSAGE);
                break;
            }

            if(count==3){
                JOptionPane.showMessageDialog(null, "You have exceeded the number of retries!", "Error", JOptionPane.ERROR_MESSAGE);
                break;
            }
        }
        while(access != pass);
    }
}