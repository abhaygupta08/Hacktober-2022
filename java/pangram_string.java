import java.util.*;

class Solution {
    public boolean checkIfPangram(String sentence) {
        HashMap<Character, Integer> mp= new HashMap<>();
        for(char c: sentence.toCharArray()){
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }
        
        char c= 'a';
        while(c<='z'){
            if(!mp.containsKey(c)){
                return false;
            }
            
            c= (char)(c+1);
        }
        
        return true;
    }
}