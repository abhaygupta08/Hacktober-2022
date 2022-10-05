// Q68 https://www.codingninjas.com/codestudio/problems/chess-tournament_981299?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: n*logn
// Space: O(1)

#include<algorithm>
bool ispossible(vector<int> pos , int n ,  int c, int mid){
    int cord=pos[0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(pos[i]-cord>=mid){
            cnt++;
            cord=pos[i];
        }
        if(cnt==c) return true;
    }
    return false;
}

int chessTournament(vector<int> pos , int n ,  int c){
    sort(pos.begin(),pos.end());
    int l=0;
    int res=-1;
    int h=pos[n-1]-pos[0];
    while(l<=h){
        int mid=(l+h)>>1;
        if(ispossible(pos,n,c,mid)){
            l=mid+1;
            res=mid;
        }
        else
            h=mid-1;
    }
    return res;
}
