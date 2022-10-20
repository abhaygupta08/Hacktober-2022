// Q58 https://www.codingninjas.com/codestudio/problems/981273?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(n^m)
// Space: O(n)+O(n)

// n=node
// m=colors

bool issafe(int node, int color[], vector<vector<int>> &mat,int n,int col){
    for(int i=0;i<n;i++){
        if(i!=node&& mat[node][i]==1&&color[i]==col)
            return false;
    }
    return true;
}

bool recf(int node,vector<vector<int>> &mat, int n, int m, int color[]){
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(issafe(node,color,mat,n,i)){
            color[node]=i;
            if(recf(node+1,mat,n,m,color)) return true;
            color[node]=0; 
        }
    }
    return false;    
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n=mat.size();
    int color[n]={0};
    if(recf(0,mat,n,m,color)) return "YES";
    else return "NO";
}
