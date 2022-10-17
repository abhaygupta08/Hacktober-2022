#include<stdio.h>
int main()
{
	char str[100],vowel[100],consonent[100];
	int i=0,a=0,b=0;
	scanf("%[^\n]",str);
	while(str[i]!='\0')
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
		{
		 	vowel[a]=str[i];
			a++;
			i++;	
		}
		else if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
		{
			consonent[b]=str[i];
			b++;
			i++;
		}
		else
			i++;		
	}
	printf("\n%s",vowel);
	printf("\n%s",consonent);
}
	
