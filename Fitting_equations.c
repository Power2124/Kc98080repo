#include<stdio.h>
#include<math.h>
void straight_line(double *,double *,int);
void parabola(double *,double *,int);
void exponant(double *,double *,int);
void geometric(double *,double *,int);
void table(double *, double *,int,int);
void sums(double *, double *,int,int);
char sum=228;
int i,cont;
double sumx,sumy,sumx2,sumxy,sumx3,sumx4,sumx2y,sumY,sumX2,sumXY,sumX,sumxY,a,b,c,m,n1,o,p,X,Y,A,B;

void main()
{
	double sumx,sumy,sumx2,sumxy,sumx3,sumx4,sumx2y,sumY,sumX2,sumXY,sumX,sumxY,a,b,c,m,n1,o,p,X,Y,A,B;
	int check=1,choice,n;
	printf("\n 1> Fitting straight line equations\n 2> Fitting parabolic equations\n 3> Fitting exponenetial curve equations\n 4> Fitting geometric curve equations\nEnter 1 or 2 or 3 or 4: ");
	scanf("%d",&choice); 
	if(choice!=1&&choice!=2&&choice!=3&&choice!=4)
	{
		printf("Enter valid choice.\n");
		main();
	}
	printf("\nFitting ");
	if(choice==1)
	printf("straight line.\n");
	else if(choice==2)
	printf("parabola.\n");
	else if(choice==3)
	printf("exponential equation.\n");
	else if(choice==4)
	printf("geometric curve.\n");
	printf("\nEnter number of sets of observations: ");
	scanf("%d",&n);
	double x[n],y[n];
	printf("\nEnter values of x: ");
	for(i=0;i<n;i++)
	scanf("%lf",&x[i]);
	printf("Enter values of y: ");
	for(i=0;i<n;i++)
	scanf("%lf",&y[i]);
	
	printf("\n");
	printf("\tx  \ty\n\n");
	for(i=0;i<n;i++)
	printf("\t%.8g  \t%.8g\n",x[i],y[i]);
	
	printf("\nIf entered values look correct,enter 1 to continue else enter 0 to go back: ");
	scanf("%d",&check);
	if(check==0)
	main();
	sums(x,y,n,choice);
}
void sums(double *x, double *y,int n,int choice)
{
	sumx=sumy=sumx2=sumxy=sumx3=sumx4=sumx2y=sumY=sumX2=sumXY=sumX=sumxY=0;
	for(i=0;i<n;i++)
	{
		sumx+=x[i];
		sumy+=y[i];
		sumx2+=pow(x[i],2);
		sumx3+=pow(x[i],3);
		sumx4+=pow(x[i],4);
		sumxy+=(x[i]*y[i]);
		sumx2y+=pow(x[i],2)*y[i];
		sumY +=log10(y[i]);
		sumxY+=log10(y[i])*x[i];
		sumX2+=pow(log10(x[i]),2);
		sumX +=log10(x[i]);
		sumXY+=log10(y[i])*log10(x[i]);
	}
	table(x,y,n,choice);
}
void table(double *x, double *y,int n,int choice)
{
	double sx[n],sy[n],sx2[n],sxy[n],sx3[n],sx4[n],sx2y[n],sX[n],sY[n],sxY[n],sX2[n],sXY[n];
	for(i=0;i<n;i++)
	{
		sx[i]=x[i];
		sy[i]=y[i];
		sx2[i]=pow(x[i],2);
		sx3[i]=pow(x[i],3);
		sx4[i]=pow(x[i],4);
		sxy[i]=x[i]*y[i];
		sx2y[i]=sx2[i]*y[i];
		sX[i]=log10(sx[i]);
		sY[i]=log10(sy[i]);
		sxY[i]=log10(sy[i])*x[i];
		sX2[i]=pow(log10(x[i]),2);
		sXY[i]=log10(x[i])*log10(y[i]);
	}
    if(choice==1)
	 {
		printf("\n");
	    printf("\tx  \t\ty   \t\tx%c  \t\txy\n\n",253);
	    for(i=0;i<n;i++)
	    printf("\t%.8g  \t\t%.8g  \t\t%.8g  \t\t%.8g\n",x[i],y[i],sx2[i],sxy[i]);
	    printf("-------------------------------------------------------------------\n");
	    printf("\t%cx= %.8g \t%cy= %.8g  \t%cx%c= %.8g \t%cxy= %.8g\n",sum,sumx,sum,sumy,sum,253,sumx2,sum,sumxy);
	 }
    else if(choice==2)
	 {
		printf("\n");
	    printf("\tx  \t\ty   \t\tx%c  \t\tx^3  \t\tx^4  \t\txy  \t\tx%cy\n\n",253,253);
	    for(i=0;i<n;i++)
	    printf("\t%.8g  \t\t%.8g  \t\t%.8g  \t\t%.8g  \t\t%.8g  \t\t%.8g  \t\t%.8g\n",x[i],y[i],sx2[i],sx3[i],sx4[i],sxy[i],sx2y[i]);
	    printf("--------------------------------------------------------------------------------------------------------------------\n");
	    printf("\t%cx= %.8g \t\t%cy= %.8g  \t%cx%c= %.8g \t%cx^3= %.8g  \t%cx^4= %.8g  \t%cxy= %.8g  \t%cx%cy= %.8g\n",sum,sumx,sum,sumy,sum,253,sumx2,sum,sumx3,sum,sumx4,sum,sumxy,sum,253,sumx2y);
	 }
	else if(choice==3)
	 {
		printf("\n");
	    printf("\tx  \t\ty   \t\tY=logy  \tx%c  \t\txY\n\n",253);
	    for(i=0;i<n;i++)
	    printf("\t%.8g  \t\t%.8g  \t\t%.04lf  \t%.8g  \t\t%.04lf\n",x[i],y[i],sY[i],sx2[i],sxY[i]);
	    printf("-------------------------------------------------------------------------------------------\n");
	    printf("\t%cx= %.8g  \t%cy= %.8g  \t%cY= %.04lf  \t%cx%c= %.8g  \t%cxY= %.04lf\n",sum,sumx,sum,sumy,sum,sumY,sum,253,sumx2,sum,sumxY);
	 }
	if(choice==4)
	{
		printf("\n");
	    printf("\tx\t\ty\t\tX=logx\t\tY=logy\t\tX%c\t\tXY\n\n",253);
	    for(i=0;i<n;i++)
	    printf("\t%.8g\t\t%.8g\t\t%.04lf\t\t%.04lf\t\t%.04lf\t\t%.04lf\n",x[i],y[i],sX[i],sY[i],sX2[i],sXY[i]);
	    printf("------------------------------------------------------------------------------------------------------------\n");
	    printf("\t%cx= %.8g\t\t%cy= %.8g\t\t%cX= %.04lf\t%cY= %.04lf\t%cX%c= %.04lf\t%cXY= %.04lf\n",sum,sumx,sum,sumy,sum,sumX,sum,sumY,sum,253,sumX2,sum,sumXY);
	 }
    if(choice==1)
	straight_line(x,y,n);
	else if(choice==2)
	parabola(x,y,n);
	else if(choice==3)
	exponant(x,y,n);
	else if(choice==4)
	geometric(x,y,n);
}
void straight_line(double *x, double *y,int n)
{
	printf("\n\nFirst normal equation (an+b%cx=%cy): %da + %.8gb = %.8g",sum,sum,n,sumx,sumy);
	printf("\n\nSecond normal equation (a%cx+b%cx^2=%cxy): %.8ga + %.8gb = %.8g",sum,sum,sum,sumx,sumx2,sumxy);
	b=((sumx*sumy)-(n*sumxy))/((sumx*sumx)-(n*sumx2));
	a=(sumy-(b*sumx))/n;
	printf("\n\nValue of a: %.8g\nValue of b: %.8g",a,b);
	printf("\n\nEquation of fitting straight line is: y = %.8g + %.8gx",a,b);
	printf("\n\nTo run the program again enter 1 else enter 0: ");
	scanf("%d",&cont);
	if(cont==1)
	main();
}
void parabola(double *x, double *y, int n)
{
	printf("\n\nFirst normal equation (na+b%cx+c%cx^2=%cy): %da + %.8gb + %.8gc = %.8g",sum,sum,sum,n,sumx,sumx2,sumy);
	printf("\n\nSecond normal equation (a%cx+b%cx^2+c%cx^3=%cxy): %.8ga + %.8gb + %.8gc = %.8g",sum,sum,sum,sum,sumx,sumx2,sumx3,sumxy);
	printf("\n\nThird normal equation (a%cx^2+b%cx^3+c%cx^4=%c(x^2)y): %.8ga + %.8gb + %.8gc = %.8g",sum,sum,sum,sum,sumx2,sumx3,sumx4,sumx2y);
	m=((sumxy*sumx2)-(sumx*sumx2y))*((sumx*sumx)-(n*sumx2));
	n1=((sumy*sumx)-(n*sumxy))*((sumx2*sumx2)-(sumx3*sumx));
	o=((sumx2*sumx3)-(sumx4*sumx))*((sumx*sumx)-(n*sumx2));
	p=((sumx2*sumx)-(n*sumx3))*((sumx2*sumx2)-(sumx3*sumx));
	c=(m-n1)/(o-p);
	b=(((sumx*sumy)-(n*sumxy))-(c*((sumx*sumx2)-(n*sumx3))))/((sumx*sumx)-(n*sumx2));
	a=(sumy-(sumx*b)-(sumx2*c))/n;
	printf("\n\nValue of a: %.8g\nValue of b: %.8g\nValue of c: %.8g",a,b,c);
	printf("\n\nEquation of fitting parabola is: y = %.8g + %.8gx + %.8gx%c",a,b,c,253);
	printf("\n\nTo run the program again,enter 1 else enter 0: ");
	scanf("%d",&cont);
	if(cont==1)
	main();
}
void exponant(double *x, double *y, int n)
{
	printf("\n\nFirst normal equation (An+B%cx=%cy): %dA + %.8gB = %.8g",sum,sum,n,sumx,sumY);
	printf("\n\nSecond normal equation (A%cx+B%cx^2=%cxy): %.8gA + %.8gB = %.8g",sum,sum,sum,sumx,sumx2,sumxY);
	B=((sumx*sumY)-(n*sumxY))/((sumx*sumx)-(n*sumx2));
	A=(sumY-(B*sumx))/n;
	printf("\n\nValue of A: %.8g \nValue of B: %.8g",A,B);
	printf("\n\nValue of a (anti log of A): %.8g \nValue of b (anti log of B): %.8g",pow(10,A),pow(10,B));
	printf("\n\nEquation of fitting exponential curve is: y = %.8g * (%.8g)^x",pow(10,A),pow(10,B));
	printf("\n\nTo run the program again enter 1 else enter 0: ");
	scanf("%d",&cont);
	if(cont==1)
	main();
}
void geometric(double *x, double *y, int n)
{
	printf("\n\nFirst normal equation (An+b%cX=%cY): %dA + %.8gb = %.8g",sum,sum,n,sumx,sumY);
	printf("\n\nSecond normal equation (A%cX+b%cX^2=%cXY): %.8gA + %.8gb = %.8g",sum,sum,sum,sumX,sumX2,sumXY);
	b=((sumX*sumY)-(n*sumXY))/((sumX*sumX)-(n*sumX2));
	A=(sumY-(b*sumX))/n;
	printf("\n\nValue of A: %.8g \nValue of b: %.8g",A,b);
	printf("\nValue of a (anti log of A): %.8g ",pow(10,A));
	printf("\n\nEquation of fitting geometrical curve is: y = %.8g *x^%.8g",pow(10,A),b);
	printf("\n\nTo run the program again enter 1 else enter 0: ");
	scanf("%d",&cont);
	if(cont==1)
	main();
}
