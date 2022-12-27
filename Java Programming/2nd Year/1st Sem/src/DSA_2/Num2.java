import java.util.concurrent.TimeUnit;

public class Num2 {
    public static void main(String[] args) {
        long startTime = System.nanoTime();
		long n = 16384, sum = 0;
		
		for(long i = 0; i < n; ++i) {
            for(long j = 0; j < n*n; ++j){
                ++sum;
            }
		}
		
		long totalTime = System.nanoTime() - startTime;
		System.out.println("Nano: " + totalTime);
		
		double second = (double) totalTime / 1000000000;
		System.out.println("Second: " + second);

		long secondTime = TimeUnit.SECONDS.convert(totalTime, TimeUnit.NANOSECONDS);
        System.out.println("There are " + secondTime + " seconds.");

		System.out.println("Check value: " + sum);
    }
}
