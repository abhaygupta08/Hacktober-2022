/*
Level order traversal

Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

Example 1:

Input:
    1
  /   \ 
 3     2
Output:1 3 2
Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60

Your Task:
You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105

*/


/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/


#include<bits/stdc++.h>
using namespace std;

/*A binary tree node has data, pointer to left child
and a pointer to right child */

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new Tree Node

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
              vector <int> res;
        
        //if node is null, we return the list.
        if (node == NULL) 
        return res;
        
        //creating an empty queue for level order traversal.
        queue<Node *> q;
    
        q.push(node);
    
        while (q.empty() == false)
        {
            //storing front element of queue in list and removing it from queue.
            Node *node = q.front();
            res.push_back (node->data);
            q.pop();
    
            //storing the left child of the parent node in queue.
            if (node->left != NULL)
                q.push(node->left);
    
            //storing the right child of the parent node in queue.
            if (node->right != NULL)
                q.push(node->right);
        }
        //returning the list.
        return res;
    }
};

/*Helper function to test mirror(). Given a binary search tree,
print out its data elements in increasing sorted order */

void inOrder(struct Node* node){
    if(node == NULL){
        return;
    }
    inOrder(node->left);
    printf("%d",node->data);
    inOrder(node->right);
}

// Function to Build Tree

Node* buildTree(string str){
    //corner case
    if(str.length()==0 || str[0]=='N'){
        return NULL;
    }

    // Creating vector of strings from input
    // string after splitting by space
    vector<string>ip;
    istringstream iss(str);
    for(string str; iss >> str; ){
        ip.push_back(str);
    }
    //Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    //Push the root to the queue
    queue<Node*>queue;
    queue.push(root);

    // Starting from the second element
    int i=1;
    while(!queue.empty() && i<ip.size()){
        //Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N"){
            //Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            //Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i>=ip.size()){
            break;
        }
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N"){
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int>res=ob.levelOrder(root);
        for(int i:res)cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}

