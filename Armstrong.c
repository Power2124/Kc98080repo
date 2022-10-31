#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,digit=0,t1,t2,sum=0,p,r;
	printf("ENTER ANY NUMBER:" );
	scanf("%d",&n);
	t1=n;
	t2=t1;
    while(n!=0)
    {
    	digit++;
    	n=n/10;
	}
	for(i=1;i<=digit;i++)
	{
		r=t1%10;
	    p=pow(r,digit);
		sum=sum+p;
		t1=t1/10;
	}
	if(sum==t2)
	printf("%d IS AN ARMSTRONG NUMBER.",t2);
	else
	printf("%d IS NOT AN ARMSTRONG NUMBER.",t2);
	return 0;
}
