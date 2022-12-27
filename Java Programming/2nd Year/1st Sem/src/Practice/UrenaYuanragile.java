/*
    Assignment - Java 2021-11-17
    Subject:                        Object-Oriented Programming
    Author:                         UREÑA, YUAN RAGILE C.
    Section:                        BSCS 2-3
    Instructions:
        Compute for the total amount coming from table 1 and table 2 and 
        put it in table 3
    Notes:
	For some reason, variables with leading zeroes e.g. product codes such as
	'objTrans[2][2][0] = 00023;' returns the incorrect value of 19 when accessed. 
	However, this can be mitigated by changing it into a String and then parse it 
	as a float. So that it retains the same 'encoding format' without messing up 
	the calculations.
*/

public class UrenaYuanragile {
    public static void main(String[] args) {
	// 	Initialization
		float[][][] objTrans = new float[3][5][2];
		float totalSales = (float)0.0;

		// Table 1
	// 	Product code		                       Price
		objTrans[0][0][0] = Float.parseFloat("00002"); objTrans[0][0][1] = (float)12.35;
		objTrans[0][1][0] = Float.parseFloat("00009"); objTrans[0][1][1] = (float)8.99;
		objTrans[0][2][0] = Float.parseFloat("00023"); objTrans[0][2][1] = (float)2.75;
		objTrans[0][3][0] = Float.parseFloat("00025"); objTrans[0][3][1] = (float)4.50;
		objTrans[0][4][0] = Float.parseFloat("00026"); objTrans[0][4][1] = (float)3.21;

		// Table 2
	//	Product Code		                       Qty
		objTrans[1][0][0] = Float.parseFloat("00025"); objTrans[1][0][1] = (float)20;
		objTrans[1][1][0] = Float.parseFloat("00009"); objTrans[1][1][1] = (float)99;
		objTrans[1][2][0] = Float.parseFloat("00025"); objTrans[1][2][1] = (float)15;
		objTrans[1][3][0] = Float.parseFloat("00004"); objTrans[1][3][1] = (float)70;
		objTrans[1][4][0] = Float.parseFloat("00002"); objTrans[1][4][1] = (float)45;

		// Table 3
	//	Product Code		   	               Amount
		objTrans[2][0][0] = Float.parseFloat("00002");
		objTrans[2][1][0] = Float.parseFloat("00009");
		objTrans[2][2][0] = Float.parseFloat("00023");
		objTrans[2][3][0] = Float.parseFloat("00025");
		objTrans[2][4][0] = Float.parseFloat("00026");
		
	//  Calculation for product amount in Table 3:
		for (float[] t3Row : objTrans[2]) {
			float totalQTY = 0;
			float tempPrice = 0;
			// Check for availability
			for (float[] t2Row : objTrans[1]) {
				if (Float.compare(t2Row[0], t3Row[0]) == 0)
					totalQTY += t2Row[1];
			}
			// Look-up for price
			for (float[] t1Row : objTrans[0]) {
				if (Float.compare(t1Row[0], t3Row[0]) == 0) {
					tempPrice = t1Row[1];
					break;
				}
			}
			t3Row[1] = tempPrice*totalQTY;
		} //for (float[] t3Row : objTrans[2])
		
	//  Display Table 3:
		System.out.println("\nTable 3\nProduct Code\tAmount");
		System.out.println("-------------------------");
		for (int i = 0; i < objTrans[0].length; i++) {
		    totalSales += objTrans[2][i][1];
			System.out.println(String.format("%05.0f\t\t%.2f",
							objTrans[2][i][0],
							objTrans[2][i][1]));
		}
		System.out.print("=========================");
		System.out.println(String.format("\nTotal Sales:\t%.2f", totalSales));

    } //public static void main(String[] args)
} //public class UrenaYuanragile