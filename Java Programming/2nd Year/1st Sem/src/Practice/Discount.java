// JON RAY P. MABALOT
// BSCS 2-5
// Subject: Object Oriented Programming
// Discount Calculator
import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.event.*;
import java.text.DecimalFormat;


public class Discount extends JFrame implements ActionListener, ItemListener{
	
	//Declaring every object that will be in the JFrame (GUI)
	private JPanel Frame;
	private final ButtonGroup ButtonGroup = new ButtonGroup();
	private static JLabel lblSelling = new JLabel("Selling Price:");
	private static JLabel lblQuantity = new JLabel("Quantity:");
	private static JLabel lblDiscount = new JLabel("Discount Rate:");
	private static JLabel lblTotal = new JLabel("Total Amount:");
	private static JLabel lblLessDiscount = new JLabel("Less Discount:");
	private static JLabel lblAmountDue = new JLabel("Amount Due:");
	private static JTextField txtSelling = new JTextField();
	private static JTextField txtQuantity = new JTextField();
	private static JTextField txtTotal = new JTextField();
	private static JTextField txtLessDiscount = new JTextField();
	private static JTextField txtAmountDue = new JTextField();
	private static JButton BinaryTreesnCompute = new JButton("Compute");
	private static JButton BinaryTreesnReset = new JButton("Reset");
	private static JRadioButton rdBinaryTreesn10 = new JRadioButton("10%");
	private static JRadioButton rdBinaryTreesn15 = new JRadioButton("15%");
	
	//Declaring a decimal format for the output on the text fields
    private static final DecimalFormat df = new DecimalFormat("0.00");
    
    //declaring the double variables that will be used for the computation
	private double sellPrice,quantity,total,discountAmount,amountDue,discount;
	
	//Method for making the JFrame (GUI)
	public Discount(String Title) {
		
		//adding the objects to the JFrame and all of the setbounds are for the layout of the Frame Objects
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 232);
		Frame = new JPanel();
		Frame.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(Frame);
		Frame.setLayout(null);
		setTitle(Title);
		
		lblSelling.setBounds(10, 17, 79, 15);
		Frame.add(lblSelling);
		
		txtSelling.setBounds(107, 13, 140, 25);
		Frame.add(txtSelling);
		
		lblQuantity.setBounds(10, 47, 79, 15);
		Frame.add(lblQuantity);
		
		txtQuantity.setBounds(107, 43, 140, 25);
		Frame.add(txtQuantity);
		
		lblDiscount.setBounds(285, 13, 87, 15);
		Frame.add(lblDiscount);
		
		ButtonGroup.add(rdBinaryTreesn10);
		rdBinaryTreesn10.setBounds(285, 35, 109, 23);
		Frame.add(rdBinaryTreesn10);
		rdBinaryTreesn10.addItemListener(this);
		
		ButtonGroup.add(rdBinaryTreesn15);
		rdBinaryTreesn15.setBounds(285, 61, 109, 23);
		Frame.add(rdBinaryTreesn15);
		rdBinaryTreesn15.addItemListener(this);
		
		lblTotal.setBounds(10, 101, 87, 15);
		Frame.add(lblTotal);
		
		txtTotal.setEditable(false);
		txtTotal.setBounds(107, 97, 140, 25);
		Frame.add(txtTotal);
		
		lblLessDiscount.setBounds(10, 131, 100, 15);
		Frame.add(lblLessDiscount);
		
		txtLessDiscount.setEditable(false);
		txtLessDiscount.setBounds(107, 127, 140, 25);
		Frame.add(txtLessDiscount);
		
		lblAmountDue.setBounds(10, 161, 79, 15);
		Frame.add(lblAmountDue);
		
		txtAmountDue.setEditable(false);
		txtAmountDue.setBounds(107, 157, 140, 25);
		Frame.add(txtAmountDue);
		
		BinaryTreesnCompute.setBounds(285, 91, 109, 38);
		Frame.add(BinaryTreesnCompute);
		BinaryTreesnCompute.addActionListener(this);
			
		BinaryTreesnReset.setBounds(285, 144, 109, 38);
		Frame.add(BinaryTreesnReset);
		BinaryTreesnReset.addActionListener(this);
		
		Frame.setVisible(true);
		
	}
	
	
	//setting the discount into whichever radio button is active (10% or 15%)
	public void itemStateChanged(ItemEvent e) {
		if(e.getSource()==rdBinaryTreesn10) {
			discount=.10;
		}else if(e.getSource()==rdBinaryTreesn15) {
			discount=.15;
		}
	}

	//Method for the actions when the buttons are pressed
	public void actionPerformed(ActionEvent e) {
		//if Compute Button is pressed, else if the reset button is pressed
		if(e.getSource()==BinaryTreesnCompute) {
			//if statement to check if input text fields are empty and display an error
			if(txtSelling.getText().isEmpty() || txtQuantity.getText().isEmpty())
				JOptionPane.showMessageDialog(Frame, "Something's wrong. . . Care to check the inputs?","If no input then y comput",JOptionPane.QUESTION_MESSAGE);
			else
				compute();
		}else 
			clear();
	}
	
	//Method for computing the needed Variables for output
	public void compute() {

		//getting the input from the text fields and setting them as double for computation and catching an error if a letter/symbol is entered 
		try {
			sellPrice = Double.parseDouble(txtSelling.getText());
			quantity = Double.parseDouble(txtQuantity.getText());
		} catch(NumberFormatException nfe) {
			JOptionPane.showMessageDialog(Frame, "Please Note! letters/symbols cannot be used in the input fields.","I'm illeterate :/",JOptionPane.WARNING_MESSAGE);
		}
		
		//catch statement checking if the radio buttons are pressed or if there is zero in the input fields
		if(discount==0)
			JOptionPane.showMessageDialog(Frame, "Please Note! There is no Discount Rate Applied.","This is a program for discount. Duh",JOptionPane.WARNING_MESSAGE);
		else if(sellPrice<=0 || quantity<=0){
			JOptionPane.showMessageDialog(Frame, "Please Note! Computation is useless if there are zeros or negatives in the input fields.","What is there to compute?",JOptionPane.WARNING_MESSAGE);
		}else{

			//Computing the total amount, discount amount, and amount due
			total = sellPrice * quantity;
			discountAmount = total * discount;
			amountDue = total - discountAmount;
			
			//setting the computed variables into 2 decimal places and setting it into their respective textfields
			txtTotal.setText(String.valueOf(df.format(total)));
			txtLessDiscount.setText(String.valueOf(df.format(discountAmount)));
			txtAmountDue.setText(String.valueOf(df.format(amountDue)));
			}
		}
		
	//Method for Clearing all the Text Fields and resetting the discount
	public void clear() {
		txtSelling.setText("");
		txtQuantity.setText("");
		txtTotal.setText("");
		txtLessDiscount.setText("");
		txtAmountDue.setText("");
		ButtonGroup.clearSelection();
		discount = 0;
	}

	//Main method that includes making the Object for the JFrame 
	public static void main(String[] args) {
		
		//making a new object Discount
		Discount discount = new Discount("Discount");
		discount.setVisible(true);
	}

}
