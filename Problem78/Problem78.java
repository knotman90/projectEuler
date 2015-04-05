import java.math.BigInteger;
import java.util.ArrayList;

/*
	Let p(n) represent the number of different ways in which n coins can be separated into piles. For example, five coins can separated into piles in exactly seven different ways, so p(5)=7.

	OOOOO
	OOOO   O
	OOO   OO
	OOO   O   O
	OO   OO   O
	OO   O   O   O
	O   O   O   O   O
	Find the least value of n for which p(n) is divisible by one million.

	Equivalent to fine the number of partition of n. which can be written as

	The recurrence may be expressed with explicit finite bounds for the summation indexes j,
	p(n) = \sum_{j=1}^{\big\lfloor \tfrac{1 + \sqrt{1+24n}}{6} \big\rfloor} (-1)^{j-1} ~ p\big(n - \tfrac{j(3j - 1)}{2}\big) + \sum_{j=1}^{\big\lfloor \tfrac{-1 + \sqrt{1+24n}}{6} \big\rfloor} (-1)^{j-1} ~ p\big(n - \tfrac{j(3j + 1)}{2}\big) \,
	http://oeis.org/wiki/Partition_function
 */

public class Problem78 {
	BigInteger three = new BigInteger("3");
	BigInteger two = new BigInteger("2");
	BigInteger one = new BigInteger("1");
	BigInteger mone = new BigInteger("-1");
	BigInteger oneMillione = new BigInteger("1000000");
	/*public  BigInteger pentap(  BigInteger m){
		return (m.multiply(m.multiply(three).add(one) ).divide(two));
	}

	public  BigInteger pentam(  BigInteger m){
		return (m.multiply(m.multiply(three).subtract(one) ).divide(two));
	}
	 */
	int pentap(  int m){
		return m*(3*m+1)/2;
	}
	int pentam(  int m){
		return m*(3*m-1)/2;
	}

	public ArrayList<BigInteger> pp = new ArrayList<>();

	BigInteger solve(){
		pp.add(BigInteger.ONE);
		pp.add(BigInteger.ONE);
		boolean go=true;
		int n=1;
		while(go){
			n++;
			BigInteger c=BigInteger.ZERO;
			int bound =(int) Math.floor((1+Math.sqrt(1+24*n))/6);	
			BigInteger sign;
			int index;	
//first semisum
			for(int j=1;j<=bound;j++){
				sign = (j%2==1) ? one : mone;
				index=n- pentam(j);
				c=c.add(sign.multiply(pp.get(index)));
			}
//second semisum
			sign=mone;
			bound = (int) Math.floor((-1+Math.sqrt(1+24*n))/6);
			for(int j=1;j<=bound;j++){
				sign = (j%2==1) ? one : mone;
				index=n - pentap(j);
				c=c.add(sign.multiply(pp.get(index)));
			}
//add it to the cache vector
			pp.add(c);
			go=(c.mod(oneMillione).compareTo(BigInteger.ZERO)!=0);
		}
		return BigInteger.valueOf(n);
	}

	public static void main(String[] args) {
		Problem78 sol = new Problem78();
		BigInteger res = sol.solve();
		System.out.println("The solution is " + res);
	}
}

