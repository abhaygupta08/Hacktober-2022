import java.io.File;
import java.io.FileOutputStream;
import java.util.Scanner;

public class CreateFileWriteContents {

	public static void main(String[] args) {
		final String fileName="file";
		try {
			File f=new File(fileName);
			if(f.exists()==false)
			{
				if(f.createNewFile())
				{
					System.out.println("Created File Succesfully");
				}else
					System.out.println("file Creation failed");
			}
			String text;
			Scanner sc=new Scanner(System.in);
			System.out.println("Writing a content to file!!!!");
			text=sc.nextLine();
			FileOutputStream fis=new FileOutputStream(f);
			fis.write(text.getBytes());
			fis.flush();
			fis.close();
			System.out.println("file saved");
			
		} catch (Exception e) {
			System.out.println("oj");
		}
	}

}
