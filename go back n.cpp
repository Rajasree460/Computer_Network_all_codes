//go back n arq
#include<stdio.h>
#include<stdbool.h>

void sendFrame(int frames[],int start,int end);
void receiveAck(bool ack[],int start,int end);

int main(){
	int i,j,f,w;
	printf("enter the window size: ");
	scanf("%d",&w);
	printf("\nenter the no. of frames to transmit: ");
	scanf("%d",&f);
	int frames[f];
	bool ack[f];
	printf("\nenter %d frames: ",f);
	for(i=0;i<f;i++){
		scanf("%d",&frames[i]);
	}
	printf("with go back n arq the frames will be transmitted & acked in following manner(assume no corruptions have occured)\n\n");
	for(i=0;i<f;i+=w){
		printf("sending frame from (id) %d to %d\n",i,i+w-1);
		sendFrame(frames,i,i+w);
		printf("waiting for ack...\n");  //stimulating ack
		//stimulating ack for the frames being lost/corrupted
		for(j=i;j<i+w;j++){
			if(j%2==0){
				ack[i]=true;
			}
		}
		receiveAck(ack,i,i+w);
	}
	printf("\nall frames are successfully tansmitted & acked\n\n");
	return 0;
}

void sendFrame(int frames[],int start,int end){
	for(int i=start;i<end;i++){
		printf("sending frame %d\n",frames[i]);
	}
}

void receiveAck(bool ack[],int start,int end){
	for(int i=start;i<end;i++){
		if(ack[i]){
			printf("ack received from frame (in id) %d\n",i);
		}
		else
		{
			printf("timeout:resending frame (in id) %d\n");
		}
	}
}
