// Q81 https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

void sorts(int x, stack<int> &s){
    if(s.empty()||s.top()<=x)
        s.push(x);
    else{
        int a=s.top();
        s.pop();
        sorts(x,s);
        s.push(a);
    }
}

void sortStack(stack<int> &s){
	if(s.empty()) return;
    int x=s.top();
    s.pop();
    sortStack(s);
    sorts(x,s);
}
