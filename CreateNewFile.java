import java.io.File;

public class CreateFile {

	public static void main(String[] args) 
	{
		final String fileName="file.txt";
		try {
			File f=new File(fileName);
			if(f.createNewFile())
			{
				System.out.println("Created File");
			}else
			{
				System.out.println("file creation failed");
			}
			
		} catch (Exception e) 
		{
			e.printStackTrace();
		}
		

	}

}
