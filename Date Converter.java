//------ AI Programming ---------
// Java Exercise Q18 
// Outputs user input days information in-terms of years, months, weeks, and remaining days
// Join our underground coding movement  @freecodecs (c) May, 2019.

import java.util.Scanner;

public class Ex18DateConverter{

    public static void main(String args[]){
		Scanner userIn = new Scanner(System.in);
		
		System.out.println("Enter total # of days: ");
		int days = userIn.nextInt();
		
		//assigning modules of every remaining days to appropriate time classifications
		int years = days/365;
		int months = (days % 365)/30;
		int weeks = ((days % 365) % 30)/7;
		int dayR = ((days % 365) % 30)%7;
		
		//assigning singular and plural words
		String y = (years <= 1)? " year" : " years";
		String m = (months <= 1)? " month" : " months";
		String w = (weeks <= 1)? " week" : " weeks";
		String d = (dayR <= 1)? " day" : " days";
		
		System.out.println(days + " days are equal to: " + years + y + ", " + months + m + ", " + weeks + w + ", " + dayR + d);
	
    }
}



