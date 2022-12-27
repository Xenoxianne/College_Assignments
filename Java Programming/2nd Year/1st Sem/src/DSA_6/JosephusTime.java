/*
* Gozum, Denise Julianne S.
* BSCS 2-5
* Josephus Problem
* IDE: VSCode
*/

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class JosephusTime {
    public static void main(String[] args) {
        /**Initialization and Declaration */
        Scanner scan = new Scanner(System.in);
        Queue<Integer> q = new LinkedList<Integer>();
        int n, m;   long startTime = System.nanoTime();
        char ans = 'y';

        while(ans == 'y' || ans == 'Y'){
            System.out.println("\033[H\033[2J"); //Clear Screen

            System.out.println("===================================");
            System.out.println("           JOSEPHUS GAME           ");
            System.out.println("===================================");

            /**User Input */
            System.out.print("Enter number of players: ");  n = scan.nextInt();
            System.out.print("Enter number of passes: ");   m = scan.nextInt();

            /**Add player number to queue */
            for(int i = 0; i < n; i++){
                q.add(i+1);
            }

            System.out.println("===================================");

            /**Start Game */
            System.out.print("Order of Elimination:  " );
            //loop until one player remains
            for(int j = 0; j < n-1; j++){  

                //Number of skips for player     
                for(int k = 0; k < m; k++){
                    q.add(q.poll()); //Move front element to rear
                }

                System.out.print(q.poll() + " "); //Print and eliminate player
            }
            
            System.out.println("\nWinner: " + q.poll()); //Print winner

            System.out.println("===================================");
            System.out.print("Do you want to try again? (y/n): ");  //repeat prog
            ans = scan.next().charAt(0);
        }

        System.out.println("===================================");
        System.out.println("             THANK YOU!            ");
        System.out.println("===================================");

        scan.close();

        long totalTime = System.nanoTime() - startTime;
		System.out.println("Nano seconds: " + totalTime);
		
		double second = (double) totalTime / 1000000000;
		System.out.println("Seconds: " + second);

		long secondTime = TimeUnit.SECONDS.convert(totalTime, TimeUnit.NANOSECONDS);
        System.out.println("There are " + secondTime + " seconds.");
    }
}
