#include<stdio.h>
#include<stdlib.h>
int n,isCycle=0,components=0,count=0;
void dfs(int mat[100][100],int vis[100],int src,int parent,int comp[100])
{
    vis[src]=1;
    comp[src]=1;
    for(int v=0;v<n;v++)
    {
        count++;
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
            //printf("Component %d is :",components);
            dfs(mat,vis,i,-1,comp);
           /* for(int j=0;j<n;j++)
            {
                if(comp[j])
                printf("%d ",j);
            }*/
        }
    }
}
int main()
{
    int mat[100][100];
    FILE *fp1=fopen("dfsplot.txt","w");
    FILE *fp2=fopen("dfsplotcount.txt","w");\
    for(n=1;n<=10;n++)
    {
        count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                mat[i][j]=1;
                else
                mat[i][j]=0;
            }
        }
        fprintf(fp1,"MAtrix %d is \n",n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                fprintf(fp1,"%d ",mat[i][j]);
            }
            fprintf(fp1,"\n");
        }
        checkConnectivity(mat);
        fprintf(fp2,"%d %d\n",n,count);
    }
}