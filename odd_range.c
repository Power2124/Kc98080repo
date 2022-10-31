#include<stdio.h>
int main()
{
	int u,l,i;
	printf("Enter lower bound: ");
	scanf("%d",&l);
	printf("Enter upper bound: ");
	scanf("%d",&u);
	printf("Odd numbers between %d & %d are: ",l,u);
	for(i=l;i<=u;i++)
	{
		if(i%2!=0)
		{
			printf("%d, ",i);
		}
	}
	return 0;
}
