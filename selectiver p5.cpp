//selective repeat 
#include<stdio.h>
#include<stdbool.h>

void sendFrames(int frames[],int start,int end);
void receiveAck(bool ack[],int start,int end);

int main(){
	int i,j,f,w;
	printf("enter the window size: ");
	scanf("%d",&w);
	printf("\nenter the no. of frames: ");
	scanf("%d",&f);
	int frames[f];
	bool ack[f];
	printf("\nenter %d frames: ",f);
	for(i=0;i<f;i++){
		scanf("%d",&frames[i]);
	}
	printf("\nwith selective repeat arq the frames are sent & ack in following manner:\n\n");
	for(i=0;i<f;i+=w){
		printf("sending frames from(id) %d to %d\n",i,i+w-1);
		sendFrames(frames,i,i+w);
		printf("\nwaiting for ack......\n\n");
		//stimulating some frames being lost or corrupted
		for(j=i;j<i+w;j++){
			if(j%2==0){
				ack[j]=true; //assuming ack received
			}
		}
		receiveAck(ack,i,i+w);
	}
	printf("\nall frames are successfully sent & acked\n");
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
			printf("ack received for frame(in id):%d\n",i);
		}else{
			printf("timeout:resending frame(in id) %d\n",i);
		}
	}
}
