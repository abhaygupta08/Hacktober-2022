#include<iostream>
#include<functional>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree< int, null_type ,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main() {

    ordered_set s;

    int A[]= {1,5,2,3,6,4,10};

    int n = sizeof(A)/sizeof(int );
    
    int sum = 0;
    for(int i= 1;i<n;i++)

    {

    s.insert(A[i-1]);
    sum+= (s.size()- s.order_of_key(A[i]));
    }

    cout<<sum<<endl;


return 0;

}
