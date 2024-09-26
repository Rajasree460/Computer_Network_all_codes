//go back n arq
#include<stdio.h>
#include<stdbool.h>

void sendFrames(int frames[],int start,int end);
void receiveAck(bool ack[],int start,int end);

int main(){
	int j,i,w,f;
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
	printf("\nwith go back n arq the frames will be transmitted & acked in following manner(assume no corruption has been ocured):\n\n");
	for(i=0;i<f;i+=w){
		printf("sending frame from(id) %d to %d\n",i,i+w-1);
		sendFrames(frames,i,i+w);
		printf("waiting for ack...\n");
		//stimulating frames being lost or corrupted
		for(j=i;j<i+w;j++){
			if(j%2==0){
				ack[j]=true;  //ack received
			}
		}
		receiveAck(ack,i,i+w);
	}
	printf("\nall frames are transmitted & acked successfully.\n");
	return 0;
}

void sendFrames(int frames[],int start,int end){
	for(int i=start;i<end;i++){
		printf("sending frame:%d\n",frames[i]);
	}
}

void receiveAck(bool ack[],int start,int end){
	for(int i=start;i<end;i++){
		if(ack[i]){
			printf("ack received for frame(in id) %d\n",i);
		}
		else{
			printf("timeout:resending frame %d\n",i);
		}
	}
}