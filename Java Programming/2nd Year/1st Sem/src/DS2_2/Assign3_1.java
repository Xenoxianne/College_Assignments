/*
* Group 1: Besmonte, Gozum, Mendoza, Sison, Suzn
* BSCS 2-5
* Quiz Calculator
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;  

public class Assign3_1{
    static JLabel lbl1, lbl2, lbl3, lbl4, lbl5, lbl6, title;
    static JTextField Q1, Q2, Q3, Q4, Q5, sum, ave, low, high, sort;
    static int highest, lowest;

    public static void main(String[] args) {
        JFrame frame = new JFrame("Quiz Calculator");
        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        JButton BinaryTreesn = new JButton("CALCULATE");
        
        title = new JLabel("QUIZ CALCULATOR ");
        lbl1 = new JLabel("Grades "); 
        Q1 = new JTextField(5); Q2 = new JTextField(5);
        Q3 = new JTextField(5); Q4 = new JTextField(5); Q5 = new JTextField(5);
        lbl2 = new JLabel("Sum of Grades: "); sum = new JTextField(10);
        lbl3 = new JLabel("Average of Grades: "); ave = new JTextField(10);
        lbl4 =  new JLabel("Lowest Score: "); low = new JTextField(10);
        lbl5 =  new JLabel("Highest Score: "); high = new JTextField(10);
        lbl6 = new JLabel("Arranged Scores: "); sort = new JTextField(10);
        
        //Title
        gbc.gridx = 0; gbc.gridy = 0; gbc.fill = GridBagConstraints.HORIZONTAL;
        panel.add(title, gbc);
        
        //Grade
        gbc.gridx = 0; gbc.gridy = 1; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,5);
        panel.add(lbl1, gbc); 
        //grade 1
        gbc.gridx = 1; gbc.gridy = 1; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,5);
        panel.add(Q1, gbc); 
        //grade 2
        gbc.gridx = 2; gbc.gridy = 1; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,5);
        panel.add(Q2, gbc);
        //grade 3
        gbc.gridx = 3; gbc.gridy = 1; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,5);
        panel.add(Q3, gbc);
        //grade 4
        gbc.gridx = 4; gbc.gridy = 1; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,5);
        panel.add(Q4, gbc);
        //grade 5
        gbc.gridx = 5; gbc.gridy = 1; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,5);
        panel.add(Q5, gbc);

        //sum
        gbc.gridx = 0; gbc.gridy = 2; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,5);
        panel.add(lbl2, gbc);
        gbc.gridx = 1; gbc.gridy = 2; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridwidth = 3; gbc.insets = new Insets(10,0,0,5);
        panel.add(sum, gbc);

        //ave
        gbc.gridx = 0; gbc.gridy = 3; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,5);
        panel.add(lbl3, gbc);
        gbc.gridx = 1; gbc.gridy = 3; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridwidth = 3; gbc.insets = new Insets(10,0,0,5);
        panel.add(ave, gbc);

        //low
        gbc.gridx = 0; gbc.gridy = 4; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,5);
        panel.add(lbl4, gbc);
        gbc.gridx = 1; gbc.gridy = 4; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridwidth = 3; gbc.insets = new Insets(10,0,0,5);
        panel.add(low, gbc);    

        //high
        gbc.gridx = 0; gbc.gridy = 5; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,5);
        panel.add(lbl5, gbc);
        gbc.gridx = 1; gbc.gridy = 5; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridwidth = 3; gbc.insets = new Insets(10,0,0,5);
        panel.add(high, gbc);    
      
        //sort
        gbc.gridx = 0; gbc.gridy = 6; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,5);
        panel.add(lbl6, gbc);
        gbc.gridx = 1; gbc.gridy = 6; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridwidth = 3; gbc.insets = new Insets(10,0,0,5);
        panel.add(sort, gbc);    

        //button
        gbc.gridx = 0; gbc.gridy = 7; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridwidth = 6; gbc.insets = new Insets(10,0,0,5);
        panel.add(BinaryTreesn, gbc);
        BinaryTreesn.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                sum.setText("" + sum());
                ave.setText("" + ave());
                highlow();
                high.setText("" + highest);
                low.setText("" + lowest);
            }
        });

        frame.add(panel);
        frame.setSize(500, 300);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static int sum(){
        int GradesSum = Integer.parseInt(Q1.getText()) + Integer.parseInt(Q2.getText()) + Integer.parseInt(Q3.getText()) + Integer.parseInt(Q4.getText()) + Integer.parseInt(Q5.getText());
        return GradesSum;
    }

    public static int ave(){
        int GradesAve = sum()/5;
        return GradesAve;
    }

    public static void highlow(){
        int scores[] = {Integer.parseInt(Q1.getText()), Integer.parseInt(Q2.getText()), Integer.parseInt(Q3.getText()), Integer.parseInt(Q4.getText()), Integer.parseInt(Q5.getText())};
        lowest = scores[0]; 
        int temp;
        //Determines highest & lowest
        for(int i=0; i<5; i++){
            if(scores[i] > highest){
                highest = scores[i];
            }
            if(scores[i] < lowest){
                lowest = scores[i];
            }
        }
        //Sort 
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(scores[i] < scores[j] && i!=j){
                    temp = scores[j];
                    scores[j] = scores[i];
                    scores[i] = temp;
                }
            }
        }
        
        sort.setText("" + scores[0] + " " + scores[1] + " " + scores[2] + " " + scores[3] + " " + scores[4]);
    }
}