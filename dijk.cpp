//dijkstra
#include<stdio.h>

void dijkstra(int G[100][100],int n,int source);
void relax(int u,int v,int W[100][100],int dist[]);
int extract_min(int visited[],int dist[],int n);

void dijkstra(int G[100][100],int n,int source){
	int i;
	int dist[100],visited[100];
	for(i=0;i<n;i++){
		dist[i]=99999;
		visited[i]=0;
	}
	dist[source]=0;
	for(i=0;i<n;i++){
		int u=extract_min(visited,dist,n);
		visited[u]=1;
		
		for(int v=0;v<n;v++){
			if(!visited[v] && G[u][v]!=-1){
				relax(u,v,G,dist);
			}
		}
	}
	//print
	printf("\nvertex\tdistance from source\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\n",i,dist[i]);
	}
}

void relax(int u,int v,int W[100][100],int dist[]){
	if(dist[u]+W[u][v]<dist[v]){
		dist[v]=dist[u]+W[u][v];
	}
}

int extract_min(int visited[],int dist[],int n){
	int min=99999;
	int min_id=-1;
	for(int v=0;v<n;v++){
		if(!visited[v] && dist[v]<min){
			min=dist[v];
			min_id=v;
		}
	}
	return min_id;
}

int main(){
	int G[100][100];
	int i,j,n,source;
	printf("enter the no. of vertices: ");
	scanf("%d",&n);
	printf("\nenter the adjacent matrix(%d x %d)\n",n,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&G[i][j]);
		}
	}
	printf("\nenter the src vertex: ");
	scanf("%d",&source);
	dijkstra(G,n,source);
	return 0;
}
