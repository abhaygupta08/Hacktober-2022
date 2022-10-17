import java.util.Arrays;
import java.util.HashSet;
public class CommonStringsInArray
{
	public static void main(String[] args) 
	{
		String[] array1 = {"C", "C++", "C#", "JAVA", "SQL", "ORACLE"};
		String[] array2 = {"MySQL", "SQL", "Android", "ORACLE", "PostgreSQL", "DB2", "JAVA"};
		System.out.println("Array1 : "+Arrays.toString(array1));
		System.out.println("Array2 : "+Arrays.toString(array2));
		HashSet<String> set = new HashSet<String>();
		for (int i = 0; i < array1.length; i++)
		{
			for (int j = 0; j < array2.length; j++)
			{
				if(array1[i].equals(array2[j]))
				{
					set.add(array1[i]);
				}
			}
		}
		System.out.println("Common element : "+(set));   
	}
}
