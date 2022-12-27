import java.util.concurrent.TimeUnit;

public class Num1 {
	public static void main(String[] args) {
		long startTime = System.nanoTime();
		int n = 20, sum = 0;
		
		for(int i = 0; i < n; ++i) {
			++sum;
		}
		
		long totalTime = System.nanoTime() - startTime;
		System.out.println("Nano seconds: " + totalTime);
		
		double second = (double) totalTime / 1000000000;
		System.out.println("Seconds: " + second);

		long secondTime = TimeUnit.SECONDS.convert(totalTime, TimeUnit.NANOSECONDS);
        System.out.println("There are " + secondTime + " seconds.");
	}
}
