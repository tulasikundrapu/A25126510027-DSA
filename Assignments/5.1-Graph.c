#include <stdio.h>
#define size 100
int graph[size][size];
int visited[size];
int n;
void DFS(int vertex)
{
    int i;
    visited[vertex]=1;
    printf("%d ",vertex+1);
    for(i=0;i<n;i++)
    {
        if(graph[vertex][i]==1 && visited[i]==0)
        {
            DFS(i);
        }
    }
}
int main()
{
    int start,i,j;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting vertex (1-%d): ", n);
    scanf("%d", &start);
    if(start<1 || start>n)
    {
        printf("Invalid starting vertex.\n");
        return 1;
    }
    for (i=0;i<n;i++)
        visited[i]=0;
    printf("DFS traversal: ");
    DFS(start-1);
    printf("\n");
    return 0;
}
