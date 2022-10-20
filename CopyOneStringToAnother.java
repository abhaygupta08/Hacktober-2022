import java.util.Scanner;
public class CopyOneStringToAnother 
{
	public static void main(String[] args) 
	{
	Scanner s=new Scanner(System.in);
	System.out.println("Entr Any String");
	String x=s.nextLine();
		char [] x1=x.toCharArray();
		int size=x.length();
		char [] y=new char[size];
		int i=0;
		while(i!=size)
		{
			y[i]=x1[i];
			++i;
		}	
       System.out.println(y);
        System.out.println(x);
	}
}
