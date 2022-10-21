//Input: aaaabbbccc
//Output: abc

public static String stringCompression(String str){
     int n = str.length();
     int i = 1;
     char curr = str.charAt(0);
     StringBuilder sb = new StringBuilder();
     sb.append(curr);
     while(i < n) {
       if(curr == str.charAt(i)) {
          i++;
       } else {
          curr = str.charAt(i);
          sb.append(curr);
       }
    }
		return sb.toString();
	}

//Time Complexity : O(n)
//Space Complexity: O(1)
