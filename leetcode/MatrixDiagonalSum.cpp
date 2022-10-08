class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int sum=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( (i==j) || (i+j)== m-1){
                    sum+=mat[i][j];
                }
            }
        } 
        
        return sum;
    }
    
};
