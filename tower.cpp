#include<stdio.h>
int main()
{
	int n,i,j,res,a,k;
	printf("Enter number: ");
	scanf("%d",&n);
	a=n-1;
	for(i=1;i<=n;i++)
	{
		res=n-i;
		while((res+1)!=0)
		{
			for(j=0;j<a;j++)
				printf(" ");
			for(k=0;k<((2*i)-1);k++)
				printf("%d",i);
	    	res--;
	    	printf("\n");
			}
		a--;
	}
}
