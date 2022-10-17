import java.util.Scanner;

public class CountNumberOfVowles {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter any sentance");
		String s = sc.nextLine();
		System.out.println("Number of Vowles in sentance is "+vowelCount(s));
	}

	private static int vowelCount(String s) {
		char[] str=s.toCharArray();
		int size=str.length;
		int v_count=0;
		for(int i=0;i<size;i++)
		{
			if(str[i]=='A'||str[i]=='I'||str[i]=='O' ||str[i]=='E' ||str[i]=='U' || str[i]=='a'||str[i]=='i'||str[i]=='o' ||str[i]=='e' ||str[i]=='u')
			{
				v_count++;
			}
		}
		return v_count;
	}

}
