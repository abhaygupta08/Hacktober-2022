class solution{
  public:
  
     int safePos(int n, int k) {

        vector<int> v(n);

        for(int i=0;i<n;i++)

        { v[i]=i; }

        int count=0;

        while(v.size()>1)

        {

            count+=k-1;

            count=count%v.size();

            v.erase(v.begin()+count);

        }

        return v[0]+1;

    }
};
