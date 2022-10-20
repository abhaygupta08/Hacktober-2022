import java.io.File;

public class DisplayOnlyFIleNamesInDir {

	public static void main(String[] args) {
		int c=0;
		File f=new File("f:\\");
		String s[]=f.list();
		for(String s1:s)
		{
		  File f1=new File(f,s1);
		  if(f1.isFile())
		  {
			c++;
			System.out.println(s1);
		  }
	   }
		System.out.println(c);
	}
}
