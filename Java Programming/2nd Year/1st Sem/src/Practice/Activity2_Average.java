/*
* Gozum, Denise Julianne S.
* BSCS 2-5
* Perimeter and Area of a Polygon
* IDE: VSCode
*/

import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.*;

public class Activity2_Average implements ActionListener{

    private static JLabel title = new JLabel("AVERAGE CALCULATOR");
    private static JButton okBinaryTreesn = new JButton("Ok");                               private static JButton resetBinaryTreesn = new JButton("Reset");
    private static JLabel lbl1 = new JLabel("<html>1<sup>st</sup> number</html>");  private static JTextField num1 = new JTextField(10);
    private static JLabel lbl2 = new JLabel("<html>2<sup>nd</sup> number</html>");  private static JTextField num2 = new JTextField(10); 
    private static JLabel lbl3 = new JLabel("<html>3<sup>rd</sup> number</html>");  private static JTextField num3 = new JTextField(10); 
    private static JLabel lbl4 = new JLabel("<html>4<sup>th</sup> number</html>r"); private static JTextField num4 = new JTextField(10); 
    private static JLabel lbl5 = new JLabel("<html>5<sup>th</sup> number</html>");  private static JTextField num5 = new JTextField(10); 
    private static JLabel high = new JLabel("Highest");                             private static JTextField highTxt = new JTextField(10); 
    private static JLabel low = new JLabel("Lowest");                               private static JTextField lowTxt = new JTextField(10); 
    private static JLabel avelbl = new JLabel("Average");                           private static JTextField aveTxt = new JTextField(10); 

    public Activity2_Average(){
        JFrame frame = new JFrame("Average");
        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();

        //Title
        gbc.gridx = 0; gbc.gridy = 0; gbc.fill = GridBagConstraints.HORIZONTAL;
        panel.add(title, gbc);

        //1st number
        gbc.gridx = 0; gbc.gridy = 1; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,0);
        panel.add(lbl1, gbc);
        gbc.gridx = 1; gbc.gridy = 1; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0); num1.setBorder(new LineBorder(Color.GREEN));
        panel.add(num1, gbc);

        //2nd number
        gbc.gridx = 0; gbc.gridy = 2; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,0);
        panel.add(lbl2, gbc);
        gbc.gridx = 1; gbc.gridy = 2; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0); num1.setBorder(new LineBorder(Color.GREEN));
        panel.add(num2, gbc);

        //3rd number
        gbc.gridx = 0; gbc.gridy = 3; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,0); num2.setBorder(new LineBorder(Color.GREEN));
        panel.add(lbl3, gbc);
        gbc.gridx = 1; gbc.gridy = 3; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0); num3.setBorder(new LineBorder(Color.GREEN));
        panel.add(num3, gbc);

        //4th number
        gbc.gridx = 0; gbc.gridy = 4; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,0);
        panel.add(lbl4, gbc);
        gbc.gridx = 1; gbc.gridy = 4; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0); num4.setBorder(new LineBorder(Color.GREEN));
        panel.add(num4, gbc);

        //5th number
        gbc.gridx = 0; gbc.gridy = 5; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,0);
        panel.add(lbl5, gbc);
        gbc.gridx = 1; gbc.gridy = 5; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0); num5.setBorder(new LineBorder(Color.GREEN));
        panel.add(num5, gbc);

        //Highest
        gbc.gridx = 0; gbc.gridy = 6; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,0);
        panel.add(high, gbc);
        gbc.gridx = 1; gbc.gridy = 6; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0); highTxt.setBorder(new LineBorder(Color.GREEN));
        panel.add(highTxt, gbc); highTxt.setEditable(false); 

        //Lowest
        gbc.gridx = 0; gbc.gridy = 7; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,0);
        panel.add(low, gbc);
        gbc.gridx = 1; gbc.gridy = 7; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0); lowTxt.setBorder(new LineBorder(Color.GREEN));
        panel.add(lowTxt, gbc); lowTxt.setEditable(false);

        //Average
        gbc.gridx = 0; gbc.gridy = 8; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,0);
        panel.add(avelbl, gbc);
        gbc.gridx = 1; gbc.gridy = 8; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0); aveTxt.setBorder(new LineBorder(Color.GREEN));
        panel.add(aveTxt, gbc); aveTxt.setEditable(false);

        //Ok button
        gbc.gridx = 0; gbc.gridy = 9; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,15); okBinaryTreesn.setBorder(new LineBorder(Color.GREEN));
        panel.add(okBinaryTreesn, gbc); okBinaryTreesn.addActionListener(this);

        //Reset button
        gbc.gridx = 1; gbc.gridy = 9; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0); resetBinaryTreesn.setBorder(new LineBorder(Color.GREEN));
        panel.add(resetBinaryTreesn, gbc); resetBinaryTreesn.addActionListener(this);

        frame.add(panel);
        frame.setSize(320, 350);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    } //Activity1_Average

    /**For buttons */
    public void actionPerformed(ActionEvent e) {
        //Ok button
		if(e.getSource() == okBinaryTreesn)
			Ave();
        //Reset button
		else
			Reset();
	} //Action Performed

    /**Get highest, lowest, and average score */
    public void Ave(){
        float highest, lowest, ave = 0, sum = 0;

        try {
            float scores[] = {Float.parseFloat(num1.getText()), Float.parseFloat(num2.getText()), Float.parseFloat(num3.getText()), Float.parseFloat(num4.getText()), Float.parseFloat(num5.getText())};

            highest = scores[0]; lowest = scores[0];    //highest and lowest to 1st item in the list
            
            for(int i = 0; i < 5; i++){
                //Get highest score
                if(highest < scores[i])                 
                    highest = scores[i];

                //Get lowest score
                if(lowest > scores[i])
                    lowest = scores[i];
                
                sum += scores[i];   //get sum of all scores
            }
            sum = sum - (highest + lowest); //minus highest and lowest scores
            ave = sum/3;    //divide by 3 since highest and lowest scores are not included

            //output
            highTxt.setText("" + String.format("%.2f", highest));
            lowTxt.setText("" + String.format("%.2f", lowest));
            aveTxt.setText("" + String.format("%.2f", ave));

       }catch (NumberFormatException e) {   //catch blank or non-integer text fields
            JOptionPane.showMessageDialog(null, "Cannot accept blank/non-integer values!", "Error", JOptionPane.WARNING_MESSAGE);
            Reset();
       }
    } //Method Ave

    /**Clear everything on screen */
    public void Reset(){
        num1.setText("");
		num2.setText("");
		num3.setText("");
		num4.setText("");
		num5.setText("");
		highTxt.setText("");
		lowTxt.setText("");
		aveTxt.setText("");
        num1.requestFocusInWindow();
    } //Method reset

    public static void main(String[] args) {
        new Activity2_Average();    //call method
    } //Main Method
}
