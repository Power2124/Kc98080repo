#include<stdio.h>
int main()
{
	int x,n,k,r1,dec=0,i=0,r[500];
	printf("Enter any number: ");
	scanf("%d",&n);
	x=n;
	while(x!=0)
	{
		r1=x%2;
		r[i]=r1;
		i++;
		x=x/2;
	}
	printf("Binary value of %d is:",n);
	for(k=i-1;k>=0;k--)
		printf("%d",r[k]);
    return 0;
}
