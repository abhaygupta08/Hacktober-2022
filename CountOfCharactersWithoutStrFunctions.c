#include<stdio.h>
int main()
{
	int c=0,i;
	char a[10];
	printf("Enter the String:");
	gets(a);
	for(i=0;a[i]!='\0';i++)
		c++;
	printf("Count: %d",c);
}
