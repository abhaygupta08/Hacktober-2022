#include<string.h>
#include<stdio.h>
main()
{
	char str[100];
	int len,i,j;
	scanf("%[^\n]s",str);
	len=strlen(str);
	for(i=0;i<len;i++)	
	{
		for(j=0;j<len;j++)
		{
			if(i==j)
				printf("%c",str[i])	;
			else if(i+j==len-1)
				printf("%c",str[j])	;
			else
				printf(" ");
			
		}
		printf("\n");
	}
}
