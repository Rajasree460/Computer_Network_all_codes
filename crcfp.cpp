//crc
#include<stdio.h>
#include<stdbool.h>

bool crccheck(int msg[],int n,int poly[],int m);

int main(){
	int i,n,m;
	int msg[100],poly[100];
	printf("enter the msg length: ");
	scanf("%d",&n);
	printf("\nenter the msg bits(0's & 1's): ");
	for(i=0;i<n;i++){
		scanf("%d",&msg[i]);
	}
	printf("\nenter the poly length: ");
	scanf("%d",&m);
	printf("\nenter the poly coeff(0's & 1's): ");
	for(i=0;i<m;i++){
		scanf("%d",&poly[i]);
	}
	//append 0's to the msg for m(poly len)-1 times
	for(i=0;i<m-1;i++){
		msg[n+i]=0;
	} 
	//print the msg
	printf("\nafter appending 0's(padding) the msg for crc: ");
	for(i=0;i<n+m-1;i++){
		printf("%d ",msg[i]);
	}
	printf("\n");
	if(crccheck(msg,n,poly,m)){
		printf("crc check passed, no error occured\n");
	}else{
		printf("crc check failed,error occured\n");
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
	//check if rem is all 0s
	for(i=n-m+1;i<n;i++){
		if(msg[i]!=0){
			return false;
		}
	}
	return true;
}
