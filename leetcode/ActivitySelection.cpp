// Q48 https://www.codingninjas.com/codestudio/problems/1062712?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// SAME AS (N meetings in one room)  
// https://www.codingninjas.com/codestudio/problems/1062658?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


//Time: O(n)+O(nlogn)+O(n)
//Space: O(n)
#include<algorithm>
struct time{
    int start;
    int end;
};

bool comp(struct time &t1,struct time &t2){
    return t1.end<=t2.end;
}
    
int maximumActivities(vector<int> &s, vector<int> &e) {
    int n=s.size();
    struct time t[n];
    for(int i=0;i<n;i++)
        t[i].start=s[i], t[i].end=e[i];
    sort(t,t+n,comp);
    int le=t[0].end;
    int c=1;
    for(int i=1;i<n;i++){
        if(le<=t[i].start){
            c++;
            le=t[i].end;
        }
    }
    return c;
    
    
}
