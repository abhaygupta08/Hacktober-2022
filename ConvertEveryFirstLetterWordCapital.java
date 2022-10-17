import java.util.Scanner;
public class ConvertEveryFirstLetterWordCaptial
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		System.out.println("Enter any String");
		String x=input.nextLine();
		char []y=x.toCharArray();
		int size=x.length();		
		y[0]=(char) (y[0]-32);
		int i=1;
		while(i!=size)
		{
			if(y[i]==' ')
			{
				y[i+1]=(char) (y[i+1]-32);
			}
			i++;
		}
		System.out.println("Given String is "+x);
 		System.out.println("Converted String is " +new String(y));
	}
}
