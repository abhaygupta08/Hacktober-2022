import java.util.Scanner;

public class CountNoOfVowelsAndConsonentsInString {

	public static void main(String[] args) {
		int vCount=0,cCount=0;
		Scanner scan=new Scanner(System.in);
		System.out.println("enter any Sentence");
		String str=scan.next();
		str.toLowerCase();
		for(int i=0;i<str.length();i++) {
		if(str.charAt(i)=='a'||str.charAt(i)=='e'||str.charAt(i)=='i'||str.charAt(i)=='o'||str.charAt(i)=='u')
		{
			vCount++;
		}else
			if(str.charAt(i)>'a' && str.charAt(i)<'z')
			{
				cCount++;
			}
		}
		
		System.out.println("vowels are "+vCount);
		System.out.println("Consonents are "+cCount);
	}

}