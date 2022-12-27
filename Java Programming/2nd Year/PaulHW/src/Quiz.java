import java.util.Scanner;
public class Quiz {

	public static void main(String[] args) {
		String[] ans = new String[10];	//Store users answers

		System.out.println("----- Mema Mock Quiz -----");	//title

		//Users Answers
		for(int enterAns = 0; enterAns < 10; enterAns++){
			Questions(enterAns);	//Post Questions + choices

			try{
				UserInput(ans, enterAns); //users answers
			}catch(Exception ex){
				System.out.println("Error user input!");
			}
			ans[enterAns] = ans[enterAns].toUpperCase(); //turn into upper case letter

			//if input is other than A, B, or C (Space, integer, other letters)
			while(!ans[enterAns].matches("[ABC]")) {
				System.out.println("Please enter answer from A - C");
				UserInput(ans, enterAns); //users answers
			}
		}
		System.out.println("\n----- CHECKING -----");
		CheckScore(ans); //For Checking and Scoring
	}

	/*
	Questions and Choices for Quiz
	*/
	static void Questions(int enterAns){
		switch(enterAns){
			case 0: System.out.println("1. Panget Pol");
					System.out.println("\tA. Oo\n\tB. Yes na Yes\n\tC. Meh");
					break;
			case 1: System.out.println("2."); 
					System.out.println("\tA. Oo\n\tB. Yes na Yes\n\tC. Meh");
					break;
			case 2: System.out.println("3."); 
					System.out.println("\tA. Oo\n\tB. Yes na Yes\n\tC. Meh");
					break;
			case 3: System.out.println("4."); 
					System.out.println("\tA. Oo\n\tB. Yes na Yes\n\tC. Meh");
					break;
			case 4: System.out.println("5."); 
					System.out.println("\tA. Oo\n\tB. Yes na Yes\n\tC. Meh");
					break;
			case 5: System.out.println("6.");
					System.out.println("\tA. Oo\n\tB. Yes na Yes\n\tC. Meh");
					break;
			case 6: System.out.println("7.");
					System.out.println("\tA. Oo\n\tB. Yes na Yes\n\tC. Meh");
					break;
			case 7: System.out.println("8.");
					System.out.println("\tA. Oo\n\tB. Yes na Yes\n\tC. Meh");
					break;
			case 8: System.out.println("9.");
					System.out.println("\tA. Oo\n\tB. Yes na Yes\n\tC. Meh");
					break;
			case 9: System.out.println("10.");
					System.out.println("\tA. Oo\n\tB. Yes na Yes\n\tC. Meh");
					break;
		}
	}
	
	/*
	Users Answers
	*/
	static void UserInput(String[] ans, int count){
		Scanner scan = new Scanner(System.in);
		System.out.print("Ans: ");
		ans[count] = scan.nextLine(); ans[count] = ans[count].toUpperCase(); 
	}

	/*
	Checking and Scoring
	*/
	static void CheckScore(String[] ans){
		int score = 0; //Stores score for quiz

		String[] correctans = {"A", "A", "B", "B", "C", "C", "A", "A", "B", "B"}; //Correct Answers from 1-10

		//Prints and checks answer
		for(int printans = 0; printans < ans.length; printans++){
			System.out.print((printans+1) + ". " + ans[printans]); //prints users answers

			//Compares users answer from the correct answer
			if(correctans[printans].equals(ans[printans])){
				System.out.println(" [Correct!]");
				score++; //Adds score
			}else{
				System.out.println(" [" + correctans[printans] + "]");
			}
		}

		//Score
		System.out.println("\n--- Score: " + score + "/10");
	}

}
