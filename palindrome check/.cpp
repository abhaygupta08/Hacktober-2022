class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
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
