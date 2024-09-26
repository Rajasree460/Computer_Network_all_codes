//crc
#include<stdio.h>
#include<stdbool.h>

bool crccheck(int msg[],int n,int poly[],int m);

int main(){
	int i,n,m;
	int msg[100],poly[100];
	printf("enter the length of msg: ");
	scanf("%d",&n);
	printf("\nenter the msg bits(0s & 1s): ");
	for(i=0;i<n;i++){
		scanf("%d",&msg[i]);
	}
	printf("\nenter the length of poly: ");
	scanf("%d",&m);
	printf("\nenter the poly coefficients(0s & 1s): ");
	for(i=0;i<m;i++){
		scanf("%d",&poly[i]);
	}
	//append 0s to the msg(padding) for m(poly len)-1 times
	for(i=0;i<m-1;i++){
		msg[n+i]=0;
	}
	//print msg
	printf("\nafter padding(appnding 0s to the msg) the msg for crc is: ");
	for(i=0;i<n+m-1;i++){
		printf("%d ",msg[i]);
	}
	printf("\n");
	if(crccheck(msg,n,poly,m)){
		printf("\ncrc check passed,no error has been occured.\n");
	}else{
		printf("\ncrc check failed,error has been occured.\n");
	}
	return 0;
}

bool crccheck(int msg[],int n,int poly[],int m){
	int i,j;
	for(i=0;i<n;i++){
		if(msg[i]==1){
			for(j=0;j<m;j++){
				msg[i+j]=msg[i+j]^poly[j];   //^=xor
			}
		}
	}
	//check if the rem is all 0s
	for(i=n-m;i<n;i++){  //checking for last 4 bits
		if(msg[i]!=0){
			return false;
		}
	}
	return true;
}
