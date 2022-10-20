class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

// BRUTE  [T (O(N^2)) ]  [S (O(N^2)) ]      
        // int n=matrix.size();    
        // vector<vector<int>> rotate=matrix;
        // for(int i=0;i<n;i++)
        //     for(int j=0;j<n;j++)
        //         rotate[j][n-i-1] = matrix[i][j];
        // matrix=rotate;
        
// OPTIMAL [T (O(N^2)) + (O(N^2)) ]  [S (O(1))]
        int n=matrix.size(); 
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);  
        
        for(int i=0;i<n;i++) 
            // reverse(matrix[i].begin(),matrix[i].end());  directly this can be used T (O(N^2)) instead of below
             for(int j=0;j<n/2;j++)
                swap(matrix[i][j],matrix[i][n-1-j]);             
    
    }
    
};
