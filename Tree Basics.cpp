//------ AI Programming ---------
// Tree Sorting, Insert & Deletion 
// Join our underground coding movement @freecodecs (c) June, 2019.

#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int d, Node *l=NULL, Node *r=NULL)
		{ data =d; left=l; right=r;	}
};

Node *root = NULL;

Node *findBST(Node *n, int x)
{
	if((n == NULL) || (n->data == x))   
		return(n);  
	else if(n->data > x)
		return(findBST(n->left, x)); 
	else   
		return(findBST(n->right, x));
}

void remove(Node *RNP, Node *PDNP, int del)
{
	Node *DNP;
	if(RNP == NULL)
		cout<<"\nData not found!";
	else if (RNP->data > del) 
   		remove(RNP->left, RNP, del);
    else if(RNP->data < del)   
   		remove(RNP->right, RNP, del);
   	else {   
	   DNP = RNP;
	   if((DNP->left == NULL) && (DNP->right == NULL)) 
	   	{
	       if (PDNP->left == DNP)
		   		PDNP->left = NULL;
			else
				PDNP->right = NULL;
		delete DNP;
		}
		else {
			if(DNP->left != NULL) 
				{ 
				//find the maximum in the left
				PDNP = DNP;
				DNP = DNP->left;
				while(DNP->right != NULL)
					{
					PDNP = DNP;
					DNP = DNP->right;
					}
				RNP->data = DNP->data;
				remove(DNP, PDNP, DNP->data);
				} 
			else { 
				//find the minimum in the right
				PDNP=DNP;
				DNP=DNP->right;
				while(DNP->left != NULL) 
						{
						PDNP=DNP;
						DNP=DNP->left;
						}
				RNP->data = DNP->data;
				remove(DNP,PDNP,DNP->data);
				}   
			}  
		} 		
				
}

void add(Node *&root, Node *t)
{
	if (root == NULL)
		root = t;
	else if(t->data < root ->data)
		add(root->left, t);
	else if(t->data > root->data)
		add(root->right, t);
}
void inorder(Node *root)
{
	if(root !=NULL)
	{
		inorder(root->left);
		cout<<root->data<<"\t";
		inorder(root->right);
	}
}

void preorder(Node *root)
{
	if(root !=NULL)
	{
		cout<<root->data<<"\t";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(Node *root)
{
	if(root !=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"\t";
	}
}
int main(){
	int value, choice, n, del, x;
	Node *temp;
	
	cout<<"How many data do you want to insert ? ";
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
	cout<<"\n Enter "<<i<<" data: ";
	cin>>value;
	
	temp = new Node(value);
	add(root, temp);
	}
	
	do{
		cout<<"\n 1. Inorder";
		cout<<"\n 2. Preorder";
		cout<<"\n 3. Postorder";
		cout<<"\n 4. Delete";
		cout<<"\n 5. Search";
		cout<<"\n 6. Exit \n";
		cin>>choice;
		cout<<"\n";
		
		switch(choice){
			case 1:
				inorder(root);
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				postorder(root);
				break;
			case 4:
				cout<<"\n Enter the value data to be deleted : ";
				cin>>del;
				remove(root, root, del);
				break;
			case 5:
				cout<<"\n Enter element data: ";
				cin>>x;
				cout<<"Element found at "<<findBST(root, x)->data;
				break;
			case 6:
				break;
			default:
				cout<<"\n Wrong choice";
				break;
		}
	}while(choice !=6);
	return 0;
}