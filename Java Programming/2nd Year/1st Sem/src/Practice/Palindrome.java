import java.util.Scanner;

public class Palindrome {

    public static void main(String[] args) {

        Scanner objInput = new Scanner(System.in);         

        String strSentinel = "endprog", strWord = "", strMessage;
        int intRevCounter;
        boolean boolPalindrome;
 
        System.out.println("\nThis program checks if the word entered is a palindrome.");
        System.out.println("\nPlease enter a word or type " + 
                           strSentinel + " to quit.\n");

        while (! strWord.equals(strSentinel)) {

            System.out.print("Enter a word: ");
            strWord = objInput.next();
            strWord = strWord.toLowerCase().trim();

            if (strWord.equals(strSentinel)) {
                break;
            } else {
                boolPalindrome = true;
                intRevCounter = strWord.length() - 1;
                for (int intCounter = 0; intCounter < strWord.length(); intCounter++) {
                    
                    if (strWord.charAt(intCounter) != strWord.charAt(intRevCounter)) {
                        boolPalindrome = false;
                        break;
                    }  // if (strWord.charAt(intCounter) != strWord.charAt(intRevCounter))
                    intRevCounter--;
                     
                }  // for (int intCounter = 0; intCounter < strWord.length(); intCounter++)  
                
                strMessage = boolPalindrome ? "is a" : "is not a";
                System.out.println("Entered word " + strMessage + " palindrome.\n");                

            }  // if (strWord.equals(strSentinel))
         
        }  // while (! strWord.equals(strSentinel))

    }  // public static void main(String[] args) 

}  // public class Palindrome