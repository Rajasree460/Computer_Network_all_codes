//ssliding window
#include<stdio.h>

int main(){
	int i,w,f,frames[50];
	printf("enter the window size: ");
	scanf("%d",&w);
	printf("\nenter the no. of frames to transmit: ");
	scanf("%d",&f);
	printf("\nenter %d frames: ",f);
	for(i=1;i<=f;i++){
		scanf("%d",&frames[i]);
	}
	printf("\nwith sliding window protocol the frames will be transmitted & acked in following manner(assume no corruptions):\n\n");
	printf("\nafter sending %d frames at each stage sender will wait for acks from receiver\n\n",w);
	for(i=1;i<=f;i++){
		if(i%w==0){
			printf("%d\n",frames[i]);
			printf("acks received for the above sent frames\n");
		}else{
			printf("%d ",frames[i]);
		}
	}
		if(f%w!=0){
		    printf("acks received for the above sent frames\n");	
		}
	return 0;
}
