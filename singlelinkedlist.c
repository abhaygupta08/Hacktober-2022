#include<stdio.h>
#include<conio.h>
void insertionbeg();
void insertionend();
void insertionmid();
void deletionbeg();
void deletionend();
void deletionmid();
void search();
void display();
struct node{
int data;
struct node *next;
};
struct node* head=NULL;
int main()
{
int ch;
do{

printf("enter choice 1 for insertionbeg 2 for insertionend 3 for insertionmid 4 for deletionbeg 5 for deletionend 6 for deletionmid 7 for search 8 for display");
scanf("%d",&ch);
switch(ch)
{
case 1:insertionbeg();
      break;
case 2:insertionend();
      break;
case 3:insertionmid();
      break;
case 4:deletionbeg();
      break;
case 5:deletionend();
      break;
case 6:deletionmid();
      break;
case 7:search();
      break;
case 8:display();
      break;
default:printf("enter choice properly");
       break;

     
}

}while(ch!=9);
}
void insertionbeg()
{
int val;
printf("enter value ");
scanf("%d",&val);
struct node*newnode=malloc(sizeof(struct node*));
newnode->data=val;
newnode->next=head;
head=newnode;
}
void insertionend()
{
int val;
printf("enter value ");
scanf("%d",&val);
struct node*newnode=malloc(sizeof(struct node*));
newnode->data=val;
newnode->next=NULL;
if(head==NULL)
{
head=newnode;
}
else
{
struct node*temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
}
void insertionmid()
{
struct node*newnode,*temp;
int i,pos;
printf("enter position");
scanf("%d",&pos);
int val;
printf("enter value ");
scanf("%d",&val);
struct node*newnode2=malloc(sizeof(struct node*));
newnode2->data=val;
newnode2->next=NULL;
if(head==NULL)
{
head=newnode;
}
else
{
struct node*temp=head;
for(i=0;i<pos-1;i++)
{
temp=temp->next;
if(temp==NULL)
break;
}
if(temp!=NULL)
{
newnode2->next=temp->next;
temp->next=newnode2;
}
}
}
void deletionbeg()
{
struct node*ptr;
if(head==NULL)
{
printf("cannot delete");
}
else
{
ptr=head;
head=ptr->next;
free(ptr);
}
}
void deletionend()
{
struct node*ptr,*ptr1;
if(head==NULL)
{
printf("list is empty");
}
else if(head->next==NULL)
{
head=NULL;
free(head);
printf("only one node deleted ");

}
else
{
ptr=head;
while(ptr->next!=NULL)
{
ptr1=ptr;
ptr=ptr->next;

}
ptr1->next=NULL;
free(ptr);
printf("deleted node from last");
}
}
void deletionmid()
{
int i,pos;
printf("enter position");
scanf("%d",&pos);
struct node*temp=head;
for(i=0;i<pos-1;i++)
{
temp=temp->next;
}
temp->next=temp->next->next;


}
void search()
{
struct node*ptr;
int item,i=0,flag;
ptr=head;
if(ptr==NULL)
{
printf("empty list");
}
else
{
printf("enter item");
scanf("%d",&item);
while(ptr!=NULL)
{
if(ptr->data==item)
{
printf("item found at %d",i+1);
flag=0;
break;
}
else
{
flag=1;
}
i++;
ptr=ptr->next;
}
if(flag==1)
{
printf("not found");
}
}
}
void display()
{
struct node*newnode,*temp;
temp=head;
while(temp!=NULL)
{
printf("%d  ",temp->data);
temp=temp->next;
}
printf("\n");
}
