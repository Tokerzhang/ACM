#include<cstdio>
#include<cstring>
#define inf 1<<30
const int N=1005;

int map[N][N];
int dis[N];
bool vis[N];

void dijkstra(int n)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++)dis[i]=map[0][i];
    vis[0]=1;
    for(int k=0;k<n;k++)
    {
        int min=inf,p=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&dis[i]<min)
                min=dis[i],p=i;
        }
        vis[p]=1;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&dis[i]>dis[p]+map[p][i])
                dis[i]=dis[p]+map[p][i];
        }
    }
}

int main()
{
    int n,s,D;
    while(~scanf("%d%d%d",&n,&s,&D))
    {
    for(int i=0;i<=1000;i++)
        for(int j=0;j<=1000;j++)
            if(i!=j)map[i][j]=inf;
            else map[i][j]=0;
    for(int i=1;i<=n;i++)
    {
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        if(d<map[u][v])
        map[u][v]=map[v][u]=d;
    }
    int x;
    for(int i=1;i<=s;i++)
    {
        scanf("%d",&x);
        map[0][x]=map[x][0]=0;
    }
    dijkstra(1000);
    int min=inf;

    for(int i=1;i<=D;i++)
    {
        scanf("%d",&x);
        if(dis[x]<min) min=dis[x];
    }
    printf("%d\n",min);
    }
    return 0;

}
