#include <iostream>
using namespace std;

int main() {
	// code goes here
	int T , N;
	string S;
	
	cin>>T;
	
	for(int i = 1 ; i <= T ; i++){
	    
	    cin>>N>>S;
	    
	    int count1 = 0 , count0 = 0;
	    
	    for(int j = 0 ; j < S.length() ; j++){
	        
	        if(S[j]=='1'){
	            count1++;
	        }
	        
	        else{
	            count0++;
	        }
	    }
	    
	    if(N%2==0){
	        if((count1%2==0) && (count0%2==0)){
	            cout<<"YES"<<endl;
	        }
	        
	        else{
	            cout<<"NO"<<endl;
	        }
	    }
	    
	    else{
	        if((count1%2==0) && (count0%2!=0)){
	            cout<<"YES"<<endl;
	        }
	        
	        else if((count1%2!=0) && (count0%2==0)){
	            cout<<"YES"<<endl;
	        }
	        
	        else{
	            cout<<"NO"<<endl;
	        }
	    }
	    
	}
	return 0;
}
