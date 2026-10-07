#include<stdio.h>
#include<limits.h>
#define size 100
int main()
{
    int n, graph[size][size];
    int distance[size],visited[size];
    int source;
    int i,j,count,u,min;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the weighted adjacency matrix:\n");
    printf("(Enter 0 if there is no direct road)\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter source vertex (1-%d): ", n);
    scanf("%d", &source);
    if(source<1 || source>n)
    {
        printf("Invalid source vertex.\n");
        return 1;
    }
    source--;
    for(i=0;i<n;i++)
    {
        distance[i]=INT_MAX;
        visited[i]=0;
    }
    distance[source]=0;
    for(count=0;count<n-1;count++)
    {
        min=INT_MAX;
        u=-1;
        for(i=0;i<n;i++)
        {
            if(!visited[i] && distance[i]<min)
            {
                min=distance[i];
                u=i;
            }
        }
        if(u==-1)
            break;
        visited[u]=1;
        for(j=0;j<n;j++)
        {
            if (graph[u][j]>0 && !visited[j] && distance[u]!=INT_MAX && distance[u]+graph[u][j]<distance[j])
            {
                distance[j]=distance[u]+graph[u][j];
            }
        }
    }
    printf("\nShortest distances from vertex %d:\n", source + 1);
    for(i=0;i<n;i++)
    {
        printf("Destination %d : ", i+1);
        if (distance[i]==INT_MAX)
            printf("Not reachable\n");
        else
            printf("%d\n", distance[i]);
    }
    return 0;
}
