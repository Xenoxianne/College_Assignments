/*
* Gozum, Denise Julianne S.
* BSCS 2-5
* Discount (10% & 15%)
* IDE: VSCode
*/

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.LineBorder;

public class Activity2_Discount extends JFrame implements ActionListener, ItemListener{

    private static JLabel title = new JLabel("DISCOUNT CALCULATOR");
    private static JLabel lblSP = new JLabel("Selling Price");          private static JTextField SellingPrice = new JTextField(10);
    private static JLabel lblQ = new JLabel("Quantity");                private static JTextField Quantity = new JTextField(10);
    private static JLabel lblDR = new JLabel("DISCOUNT RATE");
    private static JLabel lblTA = new JLabel("Total Amount");           private static JTextField TotalAmount = new JTextField(10);
    private static JLabel lblLD = new JLabel("Less Discount");          private static JTextField LessDiscount = new JTextField(10);
    private static JLabel lblAD = new JLabel("Amount Due");             private static JTextField AmountDue = new JTextField(10);
    private static JButton compute = new JButton("Compute");            private static JButton reset = new JButton("Reset");
    private static ButtonGroup BinaryTreesnGrp = new ButtonGroup();
    private static JRadioButton discount10 = new JRadioButton("10%", false);   
    private static JRadioButton discount15 = new JRadioButton("15%", false);
    public static float disc, price, qty, total, lessDisc, amntDue;

    public Activity2_Discount(){
        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        
        //Title
        gbc.gridx = 0; gbc.gridy = 0; gbc.fill = GridBagConstraints.HORIZONTAL;
        panel.add(title, gbc);

        /**Input */
        //Selling Price
        gbc.gridx = 0; gbc.gridy = 1; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,0);
        panel.add(lblSP, gbc);
        gbc.gridx = 1; gbc.gridy = 1; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0); SellingPrice.setBorder(new LineBorder(Color.GREEN, 2));
        panel.add(SellingPrice, gbc);

        //Quantity
        gbc.gridx = 0; gbc.gridy = 2; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,0);
        panel.add(lblQ, gbc);
        gbc.gridx = 1; gbc.gridy = 2; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0); Quantity.setBorder(new LineBorder(Color.GREEN, 2));
        panel.add(Quantity, gbc);

        /**Discount Rate */
        gbc.gridx = 0; gbc.gridy = 3; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(20,10,0,0);
        panel.add(lblDR, gbc);

        //10% radio button
        gbc.gridx = 0; gbc.gridy = 5; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,40,0,0);
        panel.add(discount10, gbc); BinaryTreesnGrp.add(discount10);
        discount10.addItemListener(this);

        //15% radio button
        gbc.gridx = 1; gbc.gridy = 5; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,20,0,0);
        panel.add(discount15, gbc); BinaryTreesnGrp.add(discount15);
        discount15.addItemListener(this);

        /**Output */
        //Total Amount
        gbc.gridx = 0; gbc.gridy = 7; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(20,10,0,0);
        panel.add(lblTA, gbc);
        gbc.gridx = 1; gbc.gridy = 7; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(20,0,0,0); TotalAmount.setBorder(new LineBorder(Color.GREEN, 2));
        panel.add(TotalAmount, gbc); TotalAmount.setEditable(false);

        //Less Discount
        gbc.gridx = 0; gbc.gridy = 8; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,0);
        panel.add(lblLD, gbc);
        gbc.gridx = 1; gbc.gridy = 8; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0); LessDiscount.setBorder(new LineBorder(Color.GREEN, 2));
        panel.add(LessDiscount, gbc); LessDiscount.setEditable(false);

        //Amount Due
        gbc.gridx = 0; gbc.gridy = 9; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,0);
        panel.add(lblAD, gbc);
        gbc.gridx = 1; gbc.gridy = 9; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0); AmountDue.setBorder(new LineBorder(Color.GREEN, 2));
        panel.add(AmountDue, gbc); AmountDue.setEditable(false);

        /**Buttons */
        //Compute Button
        gbc.gridx = 0; gbc.gridy = 10;  gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,10,0,20); compute.setSize(5, 5);
        panel.add(compute, gbc); compute.addActionListener(this);

        //Reset Button
        gbc.gridx = 1; gbc.gridy = 10; gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10,0,0,0);
        panel.add(reset, gbc);  reset.addActionListener(this);

        getContentPane().add(panel);
        setTitle("Discount");
        setSize(320, 350);
        setLocationRelativeTo(null);
        setVisible(true);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    } //Activity2_Discount

    /**Choosing discount*/
    public void itemStateChanged(ItemEvent x){
        if(x.getSource() == discount10){ 
            disc = 0.1f;     //10% discount
        } else if(x.getSource() == discount15){
            disc = 0.15f;    //15% discount
        }
    } //Item State Perform

    /**For buttons*/
    public void actionPerformed(ActionEvent x){
        //Compute button
        if(x.getSource() == compute){
            input();
            
        //Reset button
        } else{
            reset();
        }
    } //Action Performed

    /**Get user input*/
    public static void input(){
        try{
            //Declaration and initialization of variables
            price = Float.parseFloat(SellingPrice.getText());
            qty = Float.parseFloat(Quantity.getText());

            //Input is either Zero || Negative integers
            if(price<=0 || qty<=0){
                JOptionPane.showMessageDialog(null, "Negative or zero integers are not allowed!", "Error", JOptionPane.WARNING_MESSAGE);
                reset();
            }else{
                compute();
            }
        } catch(NumberFormatException e) {   //catch blank or non-integer text fields
            JOptionPane.showMessageDialog(null, "Cannot accept blank/non-integer values!", "Error", JOptionPane.WARNING_MESSAGE);
            reset();
        }
    } //Method input

    /**Compute Prices*/
    public static void compute(){
        //No discount selected
        if(disc == 0){
            JOptionPane.showMessageDialog(null, "No discount selected!\nPlease select a discount to apply", "Error", JOptionPane.WARNING_MESSAGE);

        //Discount selected
        }else{
            //Computation
            total = price * qty;            //Total orig price
            lessDisc = total * disc;        //Discounted price
            amntDue = total - lessDisc;     //Final amount

            //Output
            TotalAmount.setText(String.valueOf(String.format("%.2f", total)));
            LessDiscount.setText(String.valueOf(String.format("%.2f", lessDisc)));
            AmountDue.setText(String.valueOf(String.format("%.2f", amntDue)));
        }
    } //Method compute

    /**Clears everything on screen*/
    public static void reset(){
        SellingPrice.setText(" ");
        Quantity.setText(" ");
        BinaryTreesnGrp.clearSelection();
        TotalAmount.setText(" ");
        LessDiscount.setText(" ");
        AmountDue.setText(" ");
        SellingPrice.requestFocusInWindow();
        disc = 0;
    } //Method reset

    /**Main method*/
    public static void main(String[] args) {
        new Activity2_Discount(); //Call method
    } //Main method
}