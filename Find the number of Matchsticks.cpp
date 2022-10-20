// Find the number of Matchsticks
// GFG

class Solution{
	public:
	int find(int n,int a[])
	{
	    //code here
	    deque<int> v;
	    for(int i=0; i<n; i++)v.push_back(a[i]);
	    int k=n;
	   // cout<<k<<endl;
	    while(k!=1)
	    {
	        for(int i=0; i<k; i+=2)
	        {
	            int n1=v.front();
	            v.pop_front();
	            int n2=v.front();
	            v.pop_front();
	            
	            v.push_back(abs(n1-n2));
	        }
	        k/=2;
	    }
	    return v.front();
	}
};
