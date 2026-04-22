#include <stdio.h>
#define INF 99999
void floydWarshall(int dist[][10],int n){
int i,j,k;
for(k=0;k<n;k++){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(dist[i][k]+dist[k][j]<dist[i][j]){
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
}
}
int main(){
int n,i,j;
int graph[10][10];
printf("Enter number of vertices:");
scanf("%d",&n);

printf("Enter Adjacency matrix (use 99999 for INF):\n");
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        scanf("%d",&graph[i][j]);

        floydWarshall(graph,n);
        printf("Shortest distance matrix \n");

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j] ==INF)
                    printf("INF");
                else
                    printf("%d",graph[i][j]);
            }
            printf("\n");
        }
        return 0;



}
