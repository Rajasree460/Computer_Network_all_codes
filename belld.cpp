//bellmanford
#include<stdio.h>
#include<limits.h>

void bellmanford(int G[100][100],int V,int e,int src){
	int i,j,dist[V];
	for(i=0;i<V;i++){
		dist[i]=INT_MAX;
	}
	dist[src]=0;
	//v-1 as,we can go from a src to destination by v-1 edges(paths)
	for(i=0;i<V-1;i++){
		for(j=0;j<e;j++){
			int u=G[j][0];
			int v=G[j][1];
			int weight=G[j][2];
			if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]){
				dist[v]=dist[u]+weight;
			}
		}
	}
	//check if the graph contains any neg edge cycle
	for(i=0;i<e;i++){
		int u=G[i][0];
		int v=G[i][1];
		int weight=G[i][2];
		if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]){
			printf("the graph contains neg cycle/neg edge\n");
			return;
		}
	}
	//print
	printf("\nvertex\tdistance from source\n");
	for(i=0;i<V;i++){
		printf("%d\t%d\n",i,dist[i]);
	}
}

int main(){
	int G[100][100];
	int i,V,e,src;
	printf("enter the no. of vertices: ");
	scanf("%d",&V);
	printf("\nenter the no. of edges: ");
	scanf("%d",&e);
	printf("\nenter the edges(src desti weight)\n");
	for(i=0;i<e;i++){
		scanf("%d %d %d",&G[i][0],&G[i][1],&G[i][2]);
	}
	printf("\enter the src vertex: ");
	scanf("%d",&src);
	bellmanford(G,V,e,src);
	return 0;
}
