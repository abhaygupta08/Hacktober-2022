int visited[50][50];
class Solution {

   int  fun(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(i<0 ||j<0 ||i>=m ||j>=n){
            return 0;

        }
        if(visited[i][j]==1 || grid[i][j]==0){
            return 0;
        }
        visited[i][j]=1;
       int x= grid[i][j]+max({fun(grid,i+1,j,n,m),fun(grid,i-1,j,n,m)
        ,fun(grid,i,j-1,n,m),fun(grid,i,j+1,n,m)});
        
        visited[i][j]=0;
        return x;

    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
       int n=grid[0].size();
       int m=grid.size();
         for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
           visited[i][j]=0;
           }}
           int y=INT_MIN;
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
           y=max(y,fun(grid,i,j,n,m));
           }
       }
        return y;
    }
};