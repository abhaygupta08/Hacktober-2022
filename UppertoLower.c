#include<stdio.h>
main()
{
	char ch[100];
	int i;
	scanf("%[^\n]s",ch);
	for(i=0;ch[i]!='\0';i++)
		if(ch[i]>='a' && ch[i]<='z') //if(ch[i]>='A' && ch[i]<='Z')
			ch[i]-=32;				//ch[i]+=32;	
	printf("%s",ch);
	
}
