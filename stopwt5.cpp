//stop & wait
#include<stdio.h>

int main(){
	int i,f,frames[50];
	printf("enter the no. of frames: ");
	scanf("%d",&f);
	printf("\nenter %d frames: ",f);
	for(i=0;i<f;i++){
		scanf("%d",&frames[i]);
	}
	printf("\nwith stop & wait arq the frames will be sent & acked as follows\n\n");
	for(i=0;i<f;i++){
		printf("sending frame:%d\n",frames[i]);
		printf("waiting for ack...\n"); //stimulating ack(lets it takes 1 unit of time)
		printf("received ack for frame:%d\n\n",frames[i]);
	}
	printf("all frames are successfully sent & acked\n");
	return 0;
}
