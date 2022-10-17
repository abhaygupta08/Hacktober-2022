// Q91 https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
#include<stack>
int findCelebrity(int n) {
 	// Write your code here.
    stack<int> s;
    for(int i=0;i<n;i++)
        s.push(i);
    while(s.size()>=2){
        int i=s.top();
        s.pop();
        int j=s.top();
        s.pop();
        if(knows(i,j))  // i is not cel
            s.push(j);
        else             // j is not cel               
            s.push(i);
    }
    
    int pot=s.top();
    for(int i=0;i<n;i++){
        if(i==pot) continue;
        if(!knows(i,pot)||knows(pot,i))
            return -1;
    }
    return pot;
}
