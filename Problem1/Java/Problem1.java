package java.projectEuler;


public class Problem1 {
	/*
	 * 
	 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
		Find the sum of all the multiples of 3 or 5 below 1000.
	 */
	public static void main(String[] args) {
	naiveSolution();	
	alternativeSolution();
	}
	
	private static void naiveSolution() {
		int sum=0;
		for(int i=3;i<1000;i++){
			if(i%3==0 || i%5==0)
				sum+=i;
		}
		System.out.println("The sum is " +sum);		
	}
	
	private static  void alternativeSolution() {
		//multiple of 3 are of type 3*k with 3*k<1000
		//multiple of 5 are of type 5*k with 5*k<1000
		//sum up all the multiple of 3 and 5 but taking care of subtracting once
		//the multiple of 3 and 5 (15*k) that have been summed twice
	  int sum= 3*sumFirstNNumber(333)+5*sumFirstNNumber(199)-15*sumFirstNNumber(66);
	  System.out.println("The sum is " +sum);	
	}
	
	private static int sumFirstNNumber(int n) {
		return (n*(n+1))/2;
	}

}
