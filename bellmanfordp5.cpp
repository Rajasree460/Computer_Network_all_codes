//bellmanford
#include<stdio.h>
#include<limits.h>

void bellmanford(int G[100][100],int V,int e,int src){
	int i,j;
	int dist[V];
	for(i=0;i<V;i++){
		dist[i]=INT_MAX;
	}
	dist[src]=0;
	for(i=0;i<V-1;i++){  //as from to go src to desti we hav max V-1 edges
		for(j=0;j<e;j++){
			int u=G[j][0];
			int v=G[j][1];
			int weight=G[j][2];
			//relax edge
			if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]){
				dist[v]=dist[u]+weight;
			}
		}
	}
	//check if the graph contains any neg edge or not
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
	printf("\nvertex\tdistance from src\n");
	for(i=0;i<V;i++){
	printf("%d\t%d\n",i,dist[i]);
	}
}

int main(){
	int i,V,e,src;
	int G[100][100];
	printf("enter the no. of vertices: ");
	scanf("%d",&V);
	printf("\nenter the no. of edgs: ");
	scanf("%d",&e);
	printf("\nenter the edges(src desti weight)\n");
	for(i=0;i<e;i++){
		scanf("%d %d %d",&G[i][0],&G[i][1],&G[i][2]);
	}
	printf("\nenter the src: ");
	scanf("%d",&src);
	bellmanford(G,V,e,src);
	return 0;
}
