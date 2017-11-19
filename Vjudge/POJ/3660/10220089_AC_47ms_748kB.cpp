#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;

const int inf = 0x3f3f3f3f;
int edge[105][105],n,m;


void floyd()
{
    for(int i=1;i<=n;i++)edge[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(edge[i][k] != inf && edge[k][j] != inf && edge[i][j] > edge[i][k] + edge[k][j])
                    edge[i][j] = edge[i][k] + edge[k][j];
            }
        }
}
int main(){
    while(scanf("%d%d",&n,&m )!=EOF){
        memset(edge,inf,sizeof(edge));
        int l,r;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&l,&r);
            edge[l][r]=1;
        }
        floyd();
        int cnt = 0,j;
        for(int i = 1;i <= n;i++) {
            for(j = 1;j <= n;j++) {
                if(edge[i][j] == inf && edge[j][i] == inf)
                    break;
            }
            if(j > n)
                cnt++;
        }
        printf("%d\n",cnt);

    }
}