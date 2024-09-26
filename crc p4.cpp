//crc
#include<stdio.h>
#include<stdbool.h>

bool crccheck(int msg[],int n,int poly[],int m);

int main(){
	int i,n,m;
	int msg[100],poly[100];
	printf("enter the length of message: ");
	scanf("%d",&n);
	printf("\nenter the message bits(0's & 1's): ");
	for(i=0;i<n;i++){
		scanf("%d",&msg[i]);
	}
	printf("\nenter the length of polynomial: ");
	scanf("%d",&m);
	printf("\nenter the polynomial coefficients(0's & 1's): ");
	for(i=0;i<m;i++){
		scanf("%d",&poly[i]);
	}
	//append 0s to the msg for poly len(m) -1 times
	for(i=0;i<m-1;i++){
		msg[n+i]=0;
	}
	//print the msg
	printf("\nafter appending 0s(padding) the message for crc is: ");
	for(i=0;i<n+m-1;i++){
		printf("%d ",msg[i]);
	}
	printf("\n");
	if(crccheck(msg,n,poly,m)){
		printf("\ncrc check passed, no error occured.\n");
	}else{
		printf("\ncrc check failed, error occured.\n");
	}
	return 0;
}

bool crccheck(int msg[],int n,int poly[],int m){
	int i,j;
	for(i=0;i<n;i++){
		if(msg[i]==1){
			for(j=0;j<m;j++){
				msg[i+j]=msg[i+j]^poly[j];
			}
		}
	}
	//check if the rem is all 0s
	for(i=n-m+1;i<n;i++){
		if(msg[i]!=0){
			return false;
		}
	}
	return true;
}
