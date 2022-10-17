import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class CountOfOccuranceWords {

	public static void main(String[] args) {
		String str="Learn Java Coding And Java Concepts Learn Programmming Coding";
		countWords(str);
	}

	private static void countWords(String str) {
		String[] words=str.split(" ");
		Map<String,Integer> map=new LinkedHashMap<>();
	    for(String word:words)
	    {
	    	if(map.containsKey(word))
	    	{
	    		map.put(word, map.get(word)+1);
	    	}else
	    	{
	    		map.put(word, 1);
	    	}
	    }
	  
	    System.out.println("Non Duplicate Words are ");
	    Set<Entry<String,Integer>> set=map.entrySet();
	    Iterator<Entry<String,Integer>> itr=set.iterator();
	    while(itr.hasNext())
	    {
	    	Map.Entry<String,Integer> entry=(Map.Entry<String,Integer>)itr.next();
	    	if(entry.getValue()==1)
	    	{
	    		System.out.println(entry.getKey());
	    	}
	    }
	    
		
	}

}
