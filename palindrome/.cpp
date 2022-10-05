
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:
 
    bool isPalindrome(Node *head)
    {
       
       Node *temp = head;
        string s = "";
        while(temp!=NULL){
            s+=temp->data;
           temp = temp->next;
        }
        for(int i=0,j=s.length()-1;j>=0;j--,i++)
       {
           if(s[i] != s[j])
           {
               return false;
           }
       }
       return true;
        
    }
};


int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
   
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
    
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

