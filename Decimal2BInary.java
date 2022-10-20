import java.util.Scanner;

public class ConvertDecimalToBInary
{
   public static int binaryFormat(int number)
   {
	   int binary[] =new int[25];
	   int index=0;
	   while(number>0)
	   {
		   binary[index++]=number%2;
		   number=number/2;
	   }
	   System.out.print("For Given number binary number is ");
	   for(int i=index-1;i>=0;i--)
	   {
		   System.out.print(binary[i]);
	   }
	   return number;
   }
	
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number which you want to convert");
		int num=sc.nextInt();
		binaryFormat(num);
	}

}

