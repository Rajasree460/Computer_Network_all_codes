/*dijkastra*/
#include <stdio.h>
void dijkstra(int G[100][100], int n, int source);
void relax(int v, int u, int w[100][100], int dist[]);
int extract_min(int q[], int dist[], int n);
void dijkstra(int G[100][100], int n, int source) {
 int distance[100];
 int visited[100];
 for (int i = 0; i < n; i++) {
 distance[i] = 99999;
 visited[i] = 0;
 }
 distance[source] = 0;
 for (int i = 0; i < n; i++) {
 int u = extract_min(visited, distance, n);
 visited[u] = 1;
 for (int v = 0; v < n; v++) {
 if (!visited[v] && G[u][v] != -1) {
 relax(v, u, G, distance);
 }
 }
 }
 printf("Vertex \t Distance from Source\n");
 for (int i = 0; i < n; i++) {
 printf("%d \t %d\n", i, distance[i]);
 }
}
void relax(int v, int u, int w[100][100], int dist[]) {
 if (w[u][v] + dist[u] < dist[v]) {
 dist[v] = w[u][v] + dist[u];
 }
}
int extract_min(int visited[], int dist[], int n) {
 int min = 99999;
 int min_index = -1;
 for (int v = 0; v < n; v++) {
 if (!visited[v] && dist[v] < min) {
 min = dist[v];
 min_index = v;
 }
 }
 return min_index;
}
int main() {
 int G[100][100];
 int n, source;
 printf("Enter the number of vertices: ");
 scanf("%d", &n);
 printf("Enter the adjacency matrix (%d x %d):\n", n, n);
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 scanf("%d", &G[i][j]);
 }
 }
 printf("Enter the source vertex: ");
 scanf("%d", &source);
 dijkstra(G, n, source);
 return 0;
}
