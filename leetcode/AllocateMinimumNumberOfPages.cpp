// Q67 codingninjas.com/codestudio/problems/ayush-gives-ninjatest_1097574?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: n*logn
// Space: O(1)

bool ispossible(int n, int m, vector <int> a, long long int mid){
    int cnt=0;
    long long int sumal=0;
    for(int i=0;i<m;i++){
        if(sumal+a[i]>mid){
            cnt++;
            sumal=a[i];
            if(sumal>mid) return false;
        }
        else{
            sumal+=a[i];
        }
    }
    if(cnt<n) return true;
    return false;
}


long long ayushGivesNinjatest(int n, int m, vector<int> a) {
	if(n>m) return -1;
    long long l=a[0];
    long long h=0;
    for(int i=0;i<m;i++){
//         l=min(l,a[i]);
        if(a[i]<l) l=a[i];
        h+=a[i];
    }
    long long ans=-1;
    while(l<=h){
        long long mid=(l+h)>>1;
        if(ispossible(n,m,a,mid)){
            h=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    return ans;
}














// int Solution::books(vector<int> &A, int B) {
// }




// public:

// int books(int* A, int n1, int B) {

int Solution::int books(vector<int> &a, int n) {
    int m=a.size();	
	if(n>m) return -1;
    int l=a[0];
    int h=0;
    for(int i=0;i<m;i++){
        l=min(l,a[i]);
        h+=a[i];
    }
    while(l<=h){
        int mid=(l+h)>>1;
        if(ispossible(n,m,a,mid)){
            h=mid-1;
        }
        else
            l=mid+1;
    }
    return l;
}


bool ispossible(int n, int m, int * a, int mid){
    int cnt=0;
    int sumal=0;
    for(int i=0;i<m;i++){
        if(sumal+a[i]>mid){
            cnt++;
            sumal=a[i];
            if(sumal>mid) return false;
        }
        else{
            sumal+=a[i];
        }
    }
    if(cnt<n) return true;
    else return false;
}
