#include<stdio.h>

struct node{
        int dist[20];
        int from[20];
}r[10];

int main(){
        int c[20][20];
        int n, i, j, k, count = 0;

        printf("Enter number of nodes: ");
        scanf("%d", &n);
        printf("Enter cost of matrix: ");
        for(i = 0;i < n;i++){
                for(j = 0;j < n;j++){
                        scanf("%d", &c[i][j]);
                        c[i][i] = 0;
                        r[i].dist[j] = c[i][j];
                        r[i].from[j] = j;
                }
        }

        do{
                count = 0;
                for(i = 0;i < n;i++)
                        for(j = 0;j < n; j++)
                                for(k = 0;k < n; k++)
                                        if(r[i].dist[j] > c[i][k] + r[k].dist[j]){
                                                r[i].dist[j] = r[i].dist[k] + r[k].dist[j];
                                                r[i].from[j] = k;
                                                count++;
                                        }
               // printf("%d\n", count);
        }while(count != 0);

        for(i = 0;i < n; i++){
                printf("\nFor router %d\n", i+1);
                for(j = 0; j < n; j++){
                        printf("Node %d via %d distance %d\n", j+1, r[i].from[j] + 1, r[i].dist[j]);
                }
        }
        return 0;
}