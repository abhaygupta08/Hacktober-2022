
public class TraditionLoopInJava
{

	public static void main(String[] args) 
	{
		//For loop
		int a[]= {10,20,30,40,50};
		int size=a.length;
		int sum=0;
		for(int i=0;i!=size;i++)
		{
			sum=sum+a[i];
		}
		System.out.println(sum);
		//While loop
		int b[]= {10,20,30,40,50};
		int size1=a.length;
		int sum1=0;
		int i=0;
		while(i!=size1)
		{
			sum1=sum1+a[i];
			i++;
		}
		System.out.println(sum1);
		//do While loop
		int c[]= {10,20,30,40,50};
		int size2=a.length;
		int sum2=0;
	    i=0;
		while(i!=size1)
		{
			sum2=sum2+a[i];
			i++;
		}
		System.out.println(sum2);

	}

}
