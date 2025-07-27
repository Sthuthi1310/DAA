#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int iscycle=0,count=0,n,adj[MAX][MAX],top[MAX],vis[MAX],ind;
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<n;i++)
    {
        count++;
        if(adj[u][i])
        {
            if(!vis[i])
            {
                dfs(i);
            }
            else if(vis[i]==1)
            iscycle=1;
        }
    }
    vis[u]=2;
    top[ind--]=u;
}
void topological(int adj[MAX][MAX])
{
    ind=n-1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        dfs(i);
    }
    if(iscycle)
    printf("Cyclic no topologicL SORT\n");
    else
    {
        printf("Acyclic graph\n");
        printf("Order is \n");
        for(int i=0;i<n;i++)
        {
            printf("%d ",top[i]);
        }
        printf("\n");
    }
}
void tester()
{
    int e,u,v;
    printf("ENter the number of vertices: \n");
    scanf("%d",&n);
    printf("ENter the number f edges: ");
    scanf("%d",&e);
    printf("Enterr the edges (u to v)\n");
    for(int i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u][v]=1;
    }
    for(int i=0;i<n;i++)
    vis[i]=0;
    topological(adj);

}
void plotter() {
    FILE *fp1 = fopen("dfstop.txt", "w");
    FILE *fp2 = fopen("dfstopcount.txt", "w");

    for (n = 1; n <= 10; n++) {
        // Reset adjacency matrix and vis
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
            for (int j = 0; j < n; j++) {
                adj[i][j] = 0;
            }
        }

        // Fill upper-triangular DAG
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                adj[i][j] = 1;
            }
        }

        // Print adjacency matrix to file
        fprintf(fp1, "Graph size: %d\n", n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(fp1, "%d ", adj[i][j]);
            }
            fprintf(fp1, "\n");
        }
        fprintf(fp1, "\n");

        // Perform topological sort and record count
        topological(adj);
        fprintf(fp2, "%d %d\n", n, count);
    }

    fclose(fp1);
    fclose(fp2);
}

int main()
{
    int choice;
    printf("Ente your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:tester();
        break;
        case 2:plotter();
        break;
        default:printf("Invalid\n");
        break;
    }
}