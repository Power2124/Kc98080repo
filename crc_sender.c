#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main() {
	char data[100],div[100],data1[100];
	int dl,divl,i,j;
	printf("Enter binary data: ");	
	scanf("%s",data);
	printf("Enter binary divisor: ");	
	scanf("%s",div);
	dl=strlen(data);
	divl=strlen(div);
	for(i=0;i<divl-1;i++)
	{
		data[dl+i]='0';
	}
	strcpy(data1,data);	
	for(i=0;i<dl;i++){
		if(data1[i]=='1'){
			for(j=0;j<divl;j++){
				if(data1[i+j]==div[j])
					data1[i+j]='0';
				else
					data1[i+j]='1';
			}
		}
	}
	for(i=dl;i<dl+(divl-1);i++)
		data[i]=data1[i];
	printf("Codeword is: %s\n",data,data1); 
}
