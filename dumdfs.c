#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int graph[100][100],visited[100],iscyclic=0,count=0;
int dfscount=0,dcount=0,path[100],d;
FILE *fp1,*fp2;


void dfs(int n,int start,int parent)
{
visited[start]=1;
path[start]=1;
count++;
fprintf(fp1,"%c ",start+65);
for(int i=0;i<n;i++)
{
dcount++;
if(d==0)
{
if(i!=parent && graph[start][i] && visited[i] && path[i]==1)
{
iscyclic=1;
}
}
else
{
if(i!=parent && graph[start][i] && visited[i])
{
iscyclic=1;
}

}


if(graph[start][i] && visited[i]==0)
{
dfs(n,i,start);
}

}
path[start]=0;

}




void cc(int n)
{
fprintf(fp1,"connected components:\n");
count=0;
dfscount=0;
dcount=0;
iscyclic=0;
dfs(n,0,-1);
dfscount++;

int start=1;

if(count==n)
{
fprintf(fp1,"\nthe graph is connected\n");
}
else
{
while(count!=n)
{
if(visited[start]!=1)
{
fprintf(fp1,"\n");
dfs(n,start,-1);
dfscount++;
}
start++;
}

fprintf(fp1,"the grapgh is not connected\n");
}
fprintf(fp1,"the number of components is %d\n",dfscount);

if(iscyclic)
{
fprintf(fp1,"the grapgh is cyclic\n");
}
else
{
fprintf(fp1,"the grapgh is not cyclic\n");
}
}


int main()
{
int n,iter=0;
fp1=fopen("dfs1.txt","w");
fp2=fopen("dfs2.txt","w");
srand(time(0));


for(n=1;n<=10;n++)
{
d=rand()%2;


for(int i=0;i<n;i++)
{
visited[i]=0;
path[i]=0;
}


for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
 if(i==j)
 {
 graph[i][j]=0;
 }
 else
 {
 graph[i][j]=rand()%2;
 }
 
 if(d==1)
 {
 graph[j][i]=graph[i][j];
 }
 
 }
}



fprintf(fp1,"iteration: %d\n",iter);
iter++;
fprintf(fp1,"graph size:%d\n",n);
fprintf(fp1, "type:%s\n",(d==0)? "directed":"undirected");
fprintf(fp1,"adjacency matrix:\n");

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
fprintf(fp1,"%d ",graph[i][j]);
}
fprintf(fp1,"\n");
}




cc(n);



fprintf(fp1,"\n\n\n\n\n\n\n");
fprintf(fp2,"%d\n",dcount);


}
}