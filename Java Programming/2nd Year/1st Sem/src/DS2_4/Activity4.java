/*
* Group 1: Besmonte, Gozum, Mendoza, Sison, Suzon
* BSCS 2-5
* Menu: #3 #4 # #5 #6
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;  
import java.util.*;

public class Activity4 extends JFrame implements ActionListener{

    private static JLabel title = new JLabel("Choose a program:");
    private static JButton sum = new JButton("Sum of numbers");
    private static JButton factorial = new JButton("Factorial");
    private static JButton permComb = new JButton("Permutatons and Combinations");
    private static JButton primeComp = new JButton("Prime and Composite");
    private static JButton exit = new JButton("Exit");
    private static String in;
    private static int repeat;

    public Activity4(){
        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        
        //Title
        gbc.gridx = 0; gbc.gridy = 0; gbc.fill = GridBagConstraints.HORIZONTAL;
        panel.add(title, gbc);

        /**Choice */
        //Sum
        gbc.gridx = 0; gbc.gridy = 1; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(15,0,0,0);
        panel.add(sum, gbc); sum.addActionListener(this);

        //Factorial
        gbc.gridx = 0; gbc.gridy = 2; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(15,0,0,0);
        panel.add(factorial, gbc); factorial.addActionListener(this);

        //Permutation and Combination
        gbc.gridx = 0; gbc.gridy = 3; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(15,0,0,0);
        panel.add(permComb, gbc); permComb.addActionListener(this);

        //Prime and Composite
        gbc.gridx = 0; gbc.gridy = 4; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(15,0,0,0);
        panel.add(primeComp, gbc); primeComp.addActionListener(this);

        //Exit
        gbc.gridx = 0; gbc.gridy = 5;
        gbc.insets = new Insets(25,70,0,70);
        panel.add(exit, gbc); exit.addActionListener(this);

        getContentPane().add(panel);
        setTitle("Menu");
        setSize(280, 300);
        setLocationRelativeTo(null);
        setVisible(true);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent x){
        setVisible(false);  //hide menu

        if(x.getSource() == sum){               //Sum button
            sum1();
            setVisible(true);  //show menu
        } else if(x.getSource() == factorial){  //Factorial button
            fact();
            setVisible(true);  //show menu
        } else if(x.getSource() == permComb){   //Permutation and Combination button
            permutation();
            setVisible(true);  //show menu
        } else if(x.getSource() == primeComp){  //Prime and Composite button
            prime();
            setVisible(true);  //show menu
        } else{                                 //Exit button
            repeat = JOptionPane.showConfirmDialog(null, "Are you sure you want to exit the application?", "Exit", JOptionPane.YES_NO_OPTION);
                if(repeat == JOptionPane.YES_OPTION){
                    JOptionPane.showMessageDialog(null, "Have a great day!", "Exit", JOptionPane.PLAIN_MESSAGE);
                    dispose();
                }
        }
    }

    /**Factorial Formula*/
    public static int factorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact = fact * i;
        }
        return fact;
	}

    /**Sum of the number from 1 up to the number inputted Program*/
    public static void sum1(){
        int sum = 0, again, value;

        do{
            //User input
            in = JOptionPane.showInputDialog(null, "Enter a number to get the sum : ", "Sum of numbers function", JOptionPane.QUESTION_MESSAGE);

            try{
                if(in != null){
                    value = Integer.parseInt(in);  //convert string to int

                    if(value >= 0){
                        //Formula
                        for (int i = 1; i <= value; i++){
                            sum += i;
                        }

                        //Output
                        JOptionPane.showMessageDialog(null, "if " + value + " is inputted, the sum is " + sum);
                        sum = 0; //reset value
                    }else{
                        JOptionPane.showMessageDialog(null, "Cannot accept negative values!", "Error", JOptionPane.WARNING_MESSAGE);
                    }

                }else{
                    break; //for the cancel button || exit loop
                }
            }catch(NumberFormatException e) {   //catch blank or non-integer text fields
                JOptionPane.showMessageDialog(null, "Cannot accept blank/non-integer values!", "Error", JOptionPane.WARNING_MESSAGE);
            }finally{
                JOptionPane.showMessageDialog(null, "test", "Try", JOptionPane.WARNING_MESSAGE);
            }

            //Repeat program
            again = (JOptionPane.showConfirmDialog(null, "Use this function again?", "Sum of numbers function", JOptionPane.YES_NO_OPTION));

        }while(again == JOptionPane.YES_OPTION);

    } //Sum method

    /**Factorial Program*/
    public static void fact(){
        int again, value, ans;

        do{
            //User input
            in = JOptionPane.showInputDialog(null, "Enter number to get the factorial : ", "Factorial function", JOptionPane.QUESTION_MESSAGE);

            try{
                if(in != null){ 
                    value = Integer.parseInt(in);  //convert string to int

                    if(value >= 0){
                        //Formula
                        ans = factorial(value);
                    
                        //Output
                        JOptionPane.showMessageDialog(null, "if " + value + " is inputted, the factorial is " + ans);
                    }else{
                        JOptionPane.showMessageDialog(null, "Cannot accept negative values!", "Error", JOptionPane.WARNING_MESSAGE);
                    }

                }else{
                    break; //for the cancel button || exit loop
                }
            }catch(NumberFormatException e) {   //catch blank or non-integer text fields
                JOptionPane.showMessageDialog(null, "Cannot accept blank/non-integer values!", "Error", JOptionPane.WARNING_MESSAGE);
            }

            //Repeat program
            again = (JOptionPane.showConfirmDialog(null, "Use this function again?", "Factorial function", JOptionPane.YES_NO_OPTION));

        }while(again == JOptionPane.YES_OPTION);

    } //Factorial method

    /**Permutation and Combination Program*/
    public static void permutation(){
        int again, valueN, valueR, permutation, combination;

        do{
            //User input for n
            in = JOptionPane.showInputDialog(null, "Enter n (objects)", "Permutation and Combination", JOptionPane.QUESTION_MESSAGE);

            try{
                if(in != null){
                    valueN = Integer.parseInt(in);  //convert string to int

                    //User input for r
                    if(valueN >= 1){
                        in = JOptionPane.showInputDialog(null, "Enter r (sample size)", "Permutation and Combination", JOptionPane.QUESTION_MESSAGE);
                
                        if(in != null){
                            valueR = Integer.parseInt(in);  //convert string to int

                            if(valueR > valueN){
                                JOptionPane.showMessageDialog(null, "r needs to be smaller than n!", "Error", JOptionPane.WARNING_MESSAGE);
                            
                            //formula
                            }else if(valueR >= 1){		
                                combination = (factorial(valueN) / (factorial(valueN - valueR) * factorial(valueR)));
                                permutation = (factorial(valueN) / (factorial(valueN - valueR)));
                
                                JOptionPane.showMessageDialog(null,"Permutation = "+permutation+"\nCombination = "+combination);
                            
                            }else{
                                JOptionPane.showMessageDialog(null, "Cannot accept values lower than 1!", "Error", JOptionPane.WARNING_MESSAGE);
                            }
                    
                        }else{
                            break; //catch blank or non-integer text fields
                        }

                    }else{
                        JOptionPane.showMessageDialog(null, "Cannot accept values lower than 1!", "Error", JOptionPane.WARNING_MESSAGE);
                    }

                }else{
                    break; //catch blank or non-integer text fields
                }
            }catch(NumberFormatException e) {   //catch blank or non-integer text fields
                JOptionPane.showMessageDialog(null, "Cannot accept blank/non-integer values!", "Error", JOptionPane.WARNING_MESSAGE);
            }

            //Repeat program
            again = (JOptionPane.showConfirmDialog(null, "Use this function again?", "Factorial function", JOptionPane.YES_NO_OPTION));

        }while(again == JOptionPane.YES_OPTION);

    } //Permutation and Combination method
    
    /**Prime and Composite Program*/
    public static void prime(){
        int num=0, repeat=0, go=0, ans=0, first=0, count=0, isComposite=0;
        String input;
        LinkedList<Integer> factors = new LinkedList<Integer>();

        do{
            num=0;  isComposite=0;  count=0;
            first=0;    repeat = 1; go=0;

            //user input
            input = JOptionPane.showInputDialog(null, "INPUT A NUMBER: " , "Prime/Composite Function", JOptionPane.INFORMATION_MESSAGE);
            if(input == null){ //Check blank input
                break;
            }

            //check if input is valid
            try{
                num = Integer.parseInt(input);
                ans = num;
                go = 1;
            }catch(Exception e){
                repeat = 0;
                JOptionPane.showMessageDialog(null, "Cannot accept blank/non-integer values!", "Error", JOptionPane.WARNING_MESSAGE);
                continue;
            }

            //catch negative integers
            if(num < 0){
                JOptionPane.showMessageDialog(null, "Prime Factorization doesn't allow integers less than 1", "Invalid Input", JOptionPane.ERROR_MESSAGE);
                repeat = 0;
                continue;
            }

            //if input is 0
            else if(num == 0){
                JOptionPane.showMessageDialog(null, "CATEGORY: NEITHER PRIME NOR COMPOSITE NUMBER\nFACTORS: " +0, "RESULTS", JOptionPane.INFORMATION_MESSAGE);
                go = 0;
            }

            //formula
            if(go==1){
                for(int i=1; i<num; i++){
                    for(int j=1; j<num; j++){
                        
                        if(first == 1 && j == 1){
                            continue;
                        }else if(ans%j == 0){
                            first = 1;
                            ans = ans / j;
                            
                            factors.add(j);
                            count++;

                            if(count == 2){
                                isComposite=1;
                            }
                            break;
                        }
                    }
                }

                //Ouput
                if(isComposite==1){
                    JOptionPane.showMessageDialog(null, "CATEGORY: COMPOSITE NUMBER\nFACTORS: " +factors, "RESULTS", JOptionPane.INFORMATION_MESSAGE);
                }

                else{
                    JOptionPane.showMessageDialog(null, "CATEGORY: PRIME NUMBER\nFACTORS: " +factors, "RESULTS", JOptionPane.INFORMATION_MESSAGE);
                }
                
                for(int i=0; i<count; i++){
                    factors.removeFirst();
                }
            }

            //repeat program
            repeat = JOptionPane.showConfirmDialog(null, "Use this function again?", "Prime/Composite Function",
			JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);

        }
        while(repeat == 0);

    } //Prime and Composite method

    public static void main(String[] args) {
        new Activity4();
    }
}
