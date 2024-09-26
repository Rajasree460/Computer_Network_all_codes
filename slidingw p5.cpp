//sliding window protocol
#include<stdio.h>

int main(){
	int i,w,f,frames[50];
	printf("enter the window size: ");
	scanf("%d",&w);
	printf("\nenter the no. of frames: ");
	scanf("%d",&f);
	printf("\nenter %d frames: ",f);
	for(i=1;i<=f;i++){
		scanf("%d",&frames[i]);
	}
	printf("\nwith sliding window protocol the frames will be sent & acked in following manner:\n\n");
	printf("after sending %d frames at each stage the sender will wait for ack from receiver\n\n",w);
	for(i=1;i<=f;i++){
		if(i%w==0){
			printf("%d\n",frames[i]);
			printf("ack received for above sent frames\n");
		}
		else{
			printf("%d ",frames[i]);
		}
		if(f%w!=0){
			printf("ack received for above sent frames\n");
		}
	}
	return 0;
}
