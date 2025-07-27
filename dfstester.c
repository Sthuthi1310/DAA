#include<stdio.h>
#include<stdlib.h>
int n,isCycle=0,components=0;
void dfs(int mat[100][100],int vis[100],int src,int parent,int comp[100])
{
    vis[src]=1;
    comp[src]=1;
    for(int v=0;v<n;v++)
    {
        if(mat[src][v])
        {
            if(!vis[v])
            {
                dfs(mat,vis,v,src,comp);
            }
            else if(v!=parent)
            isCycle=1;
        }
    }
}
void checkConnectivity(int mat[100][100])
{
    isCycle=0,components=0;
    int vis[100]={0};
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            int comp[100]={0};
            components++;
            printf("Component %d is :",components);
            dfs(mat,vis,i,-1,comp);
            for(int j=0;j<n;j++)
            {
                if(comp[j])
                printf("%d ",j);
            }
        }
    }
}
int main()
{
    int mat[100][100];
    printf("Enter the number of verices in the graph: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    checkConnectivity(mat);
    if(isCycle)
    printf("Graph is cyclic\n");
    else
    printf("The graph is acyclic\n");
    printf("Number of connected components %d \n",components);
    if(components==1)
    printf("Graph is connected\n");
    else
    printf("Graph is not connected\n");
}