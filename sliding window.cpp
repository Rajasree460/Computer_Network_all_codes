//sliding wimdow protocol
#include<stdio.h>

int main(){
	int i,f,w,frames[50];
	printf("enter the window size: ");
	scanf("%d",&w);
	printf("\nenter the no. of frames to transmit: ");
	scanf("%d",&f);
	printf("\nenter %d frames: ",f);
	for(i=0;i<f;i++){
		scanf("%d",&frames[i]);
	}
	printf("\nwith sliding window protocol the frames will be transmitted & acked in following manner(assume no corruption have occured)\n");
	printf("after sending %d frames at each stage the sender will wait for ack from receiver\n\n",w);
	for(i=1;i<=f;i++){
		if(i%w==0){
			printf("%d\n",frames[i]);
			printf("ack of above sent frames is received by sender\n");
		}
		else{
			printf("%d ",frames[i]);
		}
	}
	if(f%w!=0)
	{
		printf("ack of above sent frames is received by sender\n");
	}
	return 0;
}
