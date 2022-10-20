import java.util.Scanner;

public class DigitSum {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter any Number...");
		int num=sc.nextInt();
		int rem,sum=0;
        while(num>0)
        {
        	rem=num%10;
        	sum=sum+rem;
        	num=num/10;
        }
        System.out.println("Digital Suml is  "+sum);

	}

}
