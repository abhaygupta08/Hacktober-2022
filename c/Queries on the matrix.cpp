class solution{
  public:
     vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        // Code here
        
        vector<vector<int>> mat(n, vector<int>(n, 0));
        
        for(auto& q : Queries){
            int x1 = q[0];
            int y1 = q[1];
            int x2 = q[2];
            int y2 = q[3];
            
            for(int i=x1;i<=x2;i++) mat[i][y1]++;
            
            if(y2+1 < n){
                for(int i=x1;i<=x2;i++) mat[i][y2+1]--;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                mat[i][j] += mat[i][j-1];
            }
        }
        
        return mat;
    }
};
