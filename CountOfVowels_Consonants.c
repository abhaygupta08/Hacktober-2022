#include<stdio.h>
int main()
{
	char s1[20];
	int i,j,c=0,v=0;
	printf("Enter the String:");
	gets(s1);
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u')
			c++;
		else
			v++;
	}
	printf("Vowels Count: %d\n",c);
	printf("Consonants Count: %d",v);
	return 0;
}
	
