#include<iostream>
#include <cstdio>
using namespace std;
int dist[1010];
int vis[1010];
int map[1010][1010];
int n;
void dijkstra(int st)
{
    int i,j,k,min;
    for(i=1;i<=n;i++)
    {
        dist[i]=map[st][i];
        vis[i]=0;
    }
    vis[st]=1;
    for(i=1;i<n;i++)
    {
        k=0;
        min=100000;
        for(j=1;j<=n;j++)
            if(!vis[j]&&dist[j]<min)
            {
                min=dist[j];
                k=j;
            }
        if(k==0) break; //不加上会运行不出来，可能是因为有k没有赋值的情况下就调用了vis[k]的情况，我也是看poj 1125 的模版有这么一句，后加上的。。。
        vis[k]=1;
        for(j=1;j<=n;j++)
            if(!vis[j]&&dist[k]+map[k][j]<dist[j])
                dist[j]=dist[k]+map[k][j];

    }
    return;
}
int main()
{
    int i,j,a,b,t,w;
    while(scanf("%d%d",&t,&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                map[i][j]=100000;
        for(i=1;i<=t;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            if(w<map[a][b])
            {
                map[a][b]=w;
                map[b][a]=map[a][b];
            }//这里是判断是否有重边，应为两点之间的路，未必只有一条。
        }

        dijkstra(n);
        //for(i=1;i<=n;i++)
        //printf("%d ",dist[i]);
        printf("%d\n",dist[1]);
    }
}
