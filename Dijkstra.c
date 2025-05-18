#include <stdio.h>
#define MAX 20
#define INF 999
int dist[MAX], visited[MAX], path[MAX];
int source;
void dijkstra(int n, int graph[MAX][MAX]);
int minDistance(int n);
void printPath(int path[], int j);
void printShortest(int n);
int main() {
    int graph[MAX][MAX];
    int n;
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the weight matrix:\n");
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(n,graph);
    printShortest(n);
    return 0;
}
void dijkstra(int n, int graph[MAX][MAX]) {
    int i,u, v;
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    visited[source] = 1;
    for (i = 1; i <= n; i++){
        dist[i] = graph[source][i];
    }
    for (i = 1; i <= n; i++){
        path[i]=source;
    }
    path[source]=-1;
    for (i=1;i<=n;i++) {
        u=minDistance(n);
        visited[u]=1;
        for(v=1;v<=n;v++){
            if (!visited[v]&&graph[u][v]&&dist[u]!=INF&&dist[u]+graph[u][v]<dist[v]){
                dist[v] = dist[u]+graph[u][v];
                path[v] = u;
            }
        }
    }
}
int minDistance(int n) {
    int i,min = INF,minindex = -1;
    for (i=1;i<=n;i++){
        if (visited[i]==0&&dist[i]<=min) {
            min = dist[i];
            minindex = i;
        }
    }
    return minindex;
}
void printPath(int path[], int j) {
    if (path[j]==-1) {
        return;
    }
    printPath(path,path[j]);
    printf("-->%d",j);
}
void printShortest(int n) {
    int i;
    for (i=1;i<=n;i++) {
        if(i!=source){
            printf("The Shortest distances from node %d to %d=%d\n",source,i,dist[i]);
            printf("The shortest path from node %d to %d is",source,i);
            printf("%d",source);
            printPath(path,i);
            printf("\n");
        }
    }
}