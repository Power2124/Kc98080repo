#include<stdio.h>
void main()
{
	int ch,x3,y3,c=1;
	float x1,y1,z1,x2,y2,z2,res,sec1,sec2,dec,m,z3;
	printf("\t\t\t\t\tDEGREE MINUTE SECOND CALCULATOR\n\n");
	do 
	{
	printf("Enter choice:-\n1>Add\t2>Substract\t3>Divide\t4>Multiply\t5>Decimal\t6>Decimal->deg min sec:  ");
	scanf("%d",&ch);
	if(ch==1||ch==2)
	{
			printf("Enter first degree:");
			scanf("%f",&x1);
			printf("Enter first minute:");
			scanf("%f",&y1);
			printf("Enter first second:");
			scanf("%f",&z1);
			printf("Enter second degree:");
			scanf("%f",&x2);
			printf("Enter second minute:");
			scanf("%f",&y2);
			printf("Enter second second:");
			scanf("%f",&z2);
			sec1=(x1*3600)+(y1*60)+z1;	
			sec2=(x2*3600)+(y2*60)+z2;	
	}
	else if(ch==3||ch==4)
	{
			printf("Enter degree:");
			scanf("%f",&x1);
			printf("Enter minute:");
			scanf("%f",&y1);
			printf("Enter second:");
			scanf("%f",&z1);
			sec1=(x1*3600)+(y1*60)+z1;
	}
	switch(ch)
	{
		case 1:
			printf("Addition ");
			res=sec1+sec2;
			x3=(int)res/3600;
			y3=(int)((res/60)-(x3*60));
			z3=res-((x3*3600)+(y3*60));
			dec=(z3/3600.0)+(y3/60.0)+x3;
			printf("Result: %d%c %d%c %f%c\nDecimal value: %f%c",x3,248,y3,39,z3,34,dec,248);
		break;
		case 2:
			printf("Substraction ");
			res=sec1-sec2;
			x3=(int)res/3600;
			y3=(int)((res/60)-(x3*60));
			z3=res-((x3*3600)+(y3*60));
			dec=(z3/3600.0)+(y3/60.0)+x3;
		    printf("Result: %d%c %d%c %f%c\nDecimal value: %f%c",x3,248,y3,39,z3,34,dec,248);
		break;
		case 3:
			printf("Enter divider:");
			scanf("%f",&m);
			printf("Division ");
			res=sec1/m;	
			x3=(int)res/3600;
			y3=(int)((res/60)-(x3*60));
			z3=res-((x3*3600)+(y3*60));
			dec=(z3/3600.0)+(y3/60.0)+x3;
			printf("Result: %d%c %d%c %f%c\nDecimal value: %f%c",x3,248,y3,39,z3,34,dec,248);
		break;
		case 4:
			printf("Enter multiplier:");
			scanf("%f",&m);
			printf("Multiplication ");
			res=sec1*m;	
			x3=(int)res/3600;
			y3=(int)((res/60)-(x3*60));
			z3=res-((x3*3600)+(y3*60));
			dec=(z3/3600.0)+(y3/60.0)+x3;
			printf("Result: %d%c %d%c %f%c\nDecimal value: %f%c",x3,248,y3,39,z3,34,dec,248);
		break;
		case 5:
			printf("Deg min sec to decimal\n");
			printf("Enter degree:");
			scanf("%f",&x1);
			printf("Enter minute:");
			scanf("%f",&y1);
			printf("Enter second:");
			scanf("%f",&z1);
			dec=(z1/3600.0)+(y1/60.0)+x1;
			printf("Decimal value: %f%c",dec,248);
		break;
		case 6:
			printf("Decimal to deg min sec\n");
			printf("Enter degree:");
			scanf("%f",&x1);
			x3=(int)x1;
			res=(x1-x3)*3600;
			y3=(int)res/60.0;
			z3=res-(y3*60.0);
			printf("Result: %d%c %d%c %f%c",x3,248,y3,39,z3,34);
		break;
		default:
			printf("Oops..invalid choice");
		break;
	}
	printf("\nPress 1 to continue  0 to exit:");
	scanf("%d",&c);
	}
	while(c==1);
	printf("THANK YOU %c",3);
}
