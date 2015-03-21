package euler;

import java.util.HashMap;
import java.util.Map;

public class Problem14 {

/*
 * Caching may be much much much better if implementer without a map
 * using just plain arrays
 * */
	public static Map<Long, Long> base = new HashMap<Long,Long>();
	public static long N = 100000;
	public static long LIMIT = 1000000;

	public static void firstNSequence() {
		for(long i=0;i<N;i++){
			long n=i;
			long cont =1;
			while(n>1){
				if(base.containsKey(n))
					base.put(i, base.get(n)+cont);

				if(n %2 ==0)
					n = n/2;
				else
					n=3*n +1;

				cont++;
			}
			base.put(i, cont);
		}

	}

	public static long lngSeq(long i) {
		long n=i;
		long cont =0;
		while(n>1){
			if(base.containsKey(n))
				return  base.get(n)+cont;

			if(n %2 ==0)
				n = n/2;
			else
				n=3*n +1;

			cont++;
		}
		return cont;
	}




	public static long collatzMax(){
		long max = Long.MIN_VALUE;
		long maxIndex=N;
		for(long i=N;i<LIMIT;i++){
			long l = lngSeq(i);
			if(max < l){
				max = l;
				maxIndex=i;
			}
		}
		return maxIndex;
	}

	public static void main(String[] args) {
		firstNSequence();
		System.out.println(collatzMax());
		
	}



}

