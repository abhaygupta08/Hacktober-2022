import java.util.Scanner;

public class CountVowConstSymbolsInString 
{

	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		System.out.println("Enter any String");
		String x=input.nextLine();
		x=x.toUpperCase();
		char [] y=x.toCharArray();
		int size=y.length;
		int vowcont=0;
		int constcont=0;
		int splcont=0;
		int i=0;
		while(i!=size)
		{
			if(y[i]>='A' && y[i]<='Z')
			{
				if(y[i]=='A' || y[i]=='I' || y[i]=='O' || y[i]=='E' || y[i]=='U')
				{
					++vowcont;
				}else
				{
					++constcont;
				}
				
			}else
			{
				++splcont;
			}
			++i;
			
		}
		System.out.println(x);
		System.out.println("Vowles are :"+vowcont);
		System.out.println("Constants are :"+constcont );
		System.out.println("Special characters are :"+splcont);
	}
}
	