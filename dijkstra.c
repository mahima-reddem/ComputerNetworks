#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define W 10
int minDist(int d[] , bool s[], int n){
        int min = INT_MAX, min_idx;
        for(int i = 0;i < n; i++){
                if(s[i] == false && d[i] <= min)
                        min = d[i], min_idx = i;
        }
        return min_idx;
}

void print(int d[], int n){
        printf("Vertex distance from source: \n");
        for(int i = 0;i < n; i++)
                printf("%d \t %d\n", i, d[i]);
}

void dijkstra(int grp[][10], int n, int src){
        int dist[n];
        bool set[n];

        for(int i = 0;i < n; i++)
                dist[i] = INT_MAX, set[i] = false;

        dist[src] = 0;

        for(int i = 0;i < n-1; i++){
                int u = minDist(dist, set, n);
                set[u] = true;
                for(int j = 0; j < n; j++){
                        if(!set[j] && grp[u][j] && dist[u] != INT_MAX && dist[u] + grp[u][j] < dist[j]){
                                dist[j] = dist[u] + grp[u][j];
//                                printf("%d %d\n", j, dist[j]);
                        }

                }
        //        print(dist, n);
        }
        print(dist, n);
}

int main(){
        int n, src;
        printf("Enter number of nodes: ");
        scanf("%d", &n);

        int graph[10][10];
        printf("Graph :\n");
        for(int i =0;i < n; i++){
                for(int j = 0;j < n; j++){
                        scanf("%d", &graph[i][j]);
                }
        }

        printf("Enter source node: ");
        scanf("%d", &src);

        dijkstra(graph, n, src);
        return 0;
}