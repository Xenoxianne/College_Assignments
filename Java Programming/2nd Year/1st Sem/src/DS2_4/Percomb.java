import javax.swing.JOptionPane;

public class Percomb {

	public Percomb() {
	}
	
	public static int factorial(int n) {

        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact = fact * i;
        }
        return fact;
	}
        

	public static void main(String[] args) {
		 int permutation, combination;
		
		JOptionPane.showMessageDialog(null,"Permutation & Combination");
		
		int n = Integer.parseInt(JOptionPane.showInputDialog("Enter N (objects)"));
		int r = Integer.parseInt(JOptionPane.showInputDialog("Enter R (sample size)"));
		
		combination = (factorial(n) / (factorial(n - r) * factorial(r)));
		permutation = (factorial(n) / (factorial(n - r)));
		
		JOptionPane.showMessageDialog(null,"Permutation = "+permutation+"\nCombination = "+combination);
	}

}
