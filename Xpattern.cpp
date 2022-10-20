#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int i,n,j,a;
	scanf("%[^\n]",str);
	n=strlen(str);
	a=n-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				printf("%c",str[i]);
			else if(j==a)
				printf("%c",str[a]);
			else
				printf(" ");
		}
		printf("\n");
		a--;
	}
}
