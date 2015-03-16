package euler;

public class Problem19 {

	/*
	 * 
	 * 
		You are given the following information, but you may prefer to do some research for yourself.
		1 Jan 1900 was a Monday.
		Thirty days has September,
		April, June and November.
		All the rest have thirty-one,
		Saving February alone,
		Which has twenty-eight, rain or shine.
		And on leap years, twenty-nine.
		A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
		How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
	 * 
	 * 
	 * 
	 * */


	public static int yearS=1900;
	public static int yearE=2000;
	public static int[] monthsLng = {31,28,31,30,31,30,31,31,30,31,30,31};


	private static void solve() {
		int year=yearS;
		int month=1;
		int day  =0;
		int count=0;
		while(year<=yearE){
			if(year%4==0 &&  ((year % 100 !=0) || ((year % 100 ==0) && (year % 400 ==0))) )
				monthsLng[1]=29;
			else
				monthsLng[1]=28;

			while(month<=12){

				if(day==1 && year>=1901)
					count++;

				day+=7;
				if(day>monthsLng[month-1]){
					day=day%monthsLng[month-1];
					month++;
				}
			}
			year++;
			month=1;
		}
		System.out.println("# of Sundays:"+count);
	}



	public static void main(String[] args) {
		solve();
	}


}

