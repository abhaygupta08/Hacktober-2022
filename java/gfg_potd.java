import java.util.*;

class Solution {
    public static ArrayList<Integer> findLeastGreater(int n, int[] arr) {
        // code here
        ArrayList<Integer> ans= new ArrayList<>();
        TreeSet<Integer> st= new TreeSet<>();

        for(int i=n-1; i>=0; i--){
            st.add(arr[i]);

            Integer x = st.higher(arr[i]);
            if(x== null){
                ans.add(-1);
            }else{
                ans.add(x);
            }
        }
        Collections.reverse(ans);

        return ans;
    }
}