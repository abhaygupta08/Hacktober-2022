double findPow(double x, int n){
    if(n==0) return 1;
    if(n==1) return x;
    
    double ans=findPow(x,n/2);
    if(n&1) return x*ans*ans; //odd case
    else return ans*ans; //even case
    
}



double myPow(double x, int n) {
    //less than 0 exapmle 2^-3 = 1/2^3
    if(n<0){
        return 1/findPow(x,n); 
    }else{
        return findPow(x,n); //case >0 normal case power
    }
}
