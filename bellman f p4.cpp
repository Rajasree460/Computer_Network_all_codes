//bellman ford
#include<stdio.h>
#include<limits.h>

void bellmanF(int G[100][100],int v,int e,int src){
	int i,j,dist[v];
	for(i=0;i<v;i++){
		dist[i]=INT_MAX;
	}
	dist[src]=0;
	for(i=0;i<v-1;i++){
	  for(j=0;j<e;j++){
	  	int u=G[j][0];
	  	int v=G[j][1];
	  	int weight=G[j][2];
	  	if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]){
	  		dist[v]=dist[u]+weight;
		  }
	  }	
	}
	//check for neg edge cycle
	for(i=0;i<e;i++){
		int u=G[i][0];
	  	int v=G[i][1];
	  	int weight=G[i][2];
	  	if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]){
	  		printf("\ngraph contains neg edge\n");
	  		return;
		  }
	}
	//print
	printf("\nvertex\tdistance from src to vertex\n");
	for(i=0;i<v;i++){
		printf("%d\t%d\n",i,dist[i]);
	}
}

int main(){
	int G[100][100];
	int i,v,e,src;
	printf("enter the no. of vertices: ");
	scanf("%d",&v);
	printf("\nenter the no. of edges: ");
	scanf("%d",&e);
	printf("\enter the edges(src desti weight)\n");
	for(i=0;i<e;i++){
		scanf("%d %d %d",&G[i][0],&G[i][1],&G[i][2]);
	}
	printf("\nenter thr source: ");
	scanf("%d",&src);
	bellmanF(G,v,e,src);
	return 0;
}
