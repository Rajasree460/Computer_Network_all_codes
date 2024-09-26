//stop & wait arq
#include<stdio.h>

int main(){
	int i,f,frames[50];
	printf("enter the no. of frames to transmit: ");
	scanf("%d",&f);
	printf("\nenter %d frames: ",f);
	for(i=0;i<f;i++){
		scanf("%d",&frames[i]);
	}
	printf("\nwith stop & wait arq the frames will be transmitted & acked as follows:\n\n");
	for(i=0;i<f;i++){
		printf("sending frame:%d\n",frames[i]);
		printf("waiting for ack...\n"); //stimulating ack(let it takes 1 unit of time
        printf("ack received for frame:%d\n",frames[i]);		
	}
	printf("all frames are transmitted & acked successfully.\n");
	return 0;
}
