//stop & wait arq
#include<stdio.h>

int main(){
	int i,f,frame[50];
	printf("enter the no. of frames to transmit: ");
	scanf("%d",&f);
	printf("\nenter %d frames: ",f);
	for(i=0;i<f;i++){
		scanf("%d",&frame[i]);
	}
	printf("\nwith stop & wait arq the frames will be transmitted & acked as follows\n\n");
	for(i=0;i<f;i++){
		printf("sending frame %d\n",frame[i]);
		printf("waiting for ack....\n"); //stimulating ack(let it takes 1 unkit of time)
		printf("received ack for frame %d\n",frame[i]); 
	}
	printf("\nall frames are successfully transmitted & acked\n");
	return 0;
}
