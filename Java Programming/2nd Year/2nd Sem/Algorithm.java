import java.util.*;

public class Algorithm{
    public static void main(String args[]) {

        double Score[] = {0.5, 3.2, 2.7, 2.3, 2, 1.9, 0.9, 1.2, 3, 2.7, 3.6, 4, 0};
        String DomainName[] = {"Depression", "Anger", "Mania", "Anxiety", "Somatic Symptoms", "Suicidal Ideation", "Psychosis", "Sleep Problems", "Memory", "Repetitive Thoughts and Behaviours", "Dissociation", "Personality Functioning", "Substance Use"};
      
        System.out.println("Original array: " + Arrays.toString(Score)); //print original array
        
        int n = Score.length;
        
        /**
         * Bubble Sort
         */
        //iterate over the array comparing adjacent elements
        for (int i = 0; i < n-1; i++){
            for (int j = 0; j < n-i-1; j++){
                //if elements not in order, swap them    
                if (Score[j] < Score[j+1])  {
                    //Sort Score
                    double temp = Score[j];
                    Score[j] = Score[j+1];
                    Score[j+1] = temp;

                    //Sort Domain Name
                    String tempName = DomainName[j];
                    DomainName[j] = DomainName[j+1];
                    DomainName[j+1] = tempName;
                }
            }
        }
            
        System.out.println("Sort array: " + Arrays.toString(Score));
        System.out.println("\n\tDomain Name\t\t\tScore\t\t\tInterpretation\t\t\tRecommendation\n");

         /**
         * Linear Search
         */
        for(int i = 0; i < n; i++){
            int exists = LinearSearch(DomainName[i], n), eval;
            String interpretation = Interpretation(Score[i]);
            
            //Domain name is Psychosis, Suicidal Ideation, Substance Use
            if(exists == 1){
                eval = 1;
                System.out.println(i+1 + "\t" + DomainName[i] + "\t\t\t" +  Score[i] + "\t\t\t" + interpretation + "\t\t\t" + Recommendation(Score[i], eval));
            }
            else{
                eval = 0;
                System.out.println(i+1 + "\t" + DomainName[i] + "\t\t\t" +  Score[i] + "\t\t\t" + interpretation + "\t\t\t" + Recommendation(Score[i], eval));
            }
        }

    }

    static int LinearSearch(String array, int length) {
            switch(array){
                case "Suicidal Ideation":
                case "Psychosis":
                case "Substance Use":
                    return 1;
                default: return 0;
            }
    }

    static String Interpretation(double score){
        if(score >= 0 && score <= 0.9)
            return "None";
        else if(score >= 1 && score <= 1.9)
            return "Slight";
        else if(score >= 2 && score <= 2.9)
            return "Mild";
        else if(score >= 3 && score <= 4)
            return "Severe";
        else
            return "Error";
    }

    static String Recommendation(double score, int eval){
        if(eval == 1){
            if(score >= 1)
                return "Level 2";
            else return " ";
        }else{
            if(score >= 2)
                return "Level 2";
            else return " ";
        }
    }
}