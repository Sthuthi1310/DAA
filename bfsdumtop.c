#include<stdio.h>
#include<Stdlib.h>
#define max 100
int count=0,n,indeg[max];
void indegree(int adj[max][max])
{
    for(int i=0;i<n;i++)
    indeg[i]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(adj[i][j])
            {
                indeg[j]++;
            }
        }
    }
}
void srcremsort(int adj[max][max]) {
    int sort[max], k = 0;
   indegree(adj);

    while (k < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            count++;
            if (indeg[i] == 0) {
                found = 1;
                sort[k++] = i;
                indeg[i] = -1; // mark visited

                // Remove edges and update in-degree
                for (int j = 0; j < n; j++) {
                    if (adj[i][j])
                        indeg[j]--;
                }

                break; // restart to find next source
            }
        }

        if (!found) {
            printf("Cyclic graph. No topological sort possible.\n");
            return;
        }
    }

    printf("Topological sort is:\n");
    for (int i = 0; i < k; i++) {
        printf("%d",sort[i]);
    }
    printf("\n");
}
void tester()
{
    int adj[max][max];
    printf("Enter the size of the graph: \n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    srcremsort(adj);

}
void plotter()
{
    int adj[max][max];
    FILE *fp1=fopen("bfsplot.txt","w");
    FILE *fp2=fopen("bfsplotcount.txt","w");\
    for(n=1;n<=10;n++)
    {
        count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                adj[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                adj[i][j]=1;
            }
        }
        fprintf(fp1,"MAtrix %d is \n",n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                fprintf(fp1,"%d ",adj[i][j]);
            }
            fprintf(fp1,"\n");
        }
        srcremsort(adj);
        fprintf(fp2,"%d %d\n",n,count);
    }

}
int main()
{
    int choice;
    printf("ENter choice: \n");
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