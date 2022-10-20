package ArrayRelatedPrograms;

public class CountOfOccuranceEachElement {
	public static void main(String[] args) {
		int[] array = { 1,6,2,2,1,7,5, 3, 4, 5, 6, 6,2 };
		countOfElements(array);
	}

	public static void countOfElements(int[] a) {
		int fr[]=new  int[a.length];
		int visited=-1;
		int count;
		for(int i=0;i<a.length;i++)
		{
			count=1;
			for(int j=i+1;j<a.length;j++)
			{
				if(a[i]==a[j])
				{
					count++;
					fr[j]=visited;
				}
			}
			if(fr[i]!=visited)
			{
				fr[i]=count;
			}
		}
		System.out.println("Number of Occurance ");
		for(int i=0;i<fr.length;i++)
		{
			if(fr[i]!=visited)
			{
				System.out.println("  "+a[i]+"     |     "+fr[i]);
			}
		}
	}
}
