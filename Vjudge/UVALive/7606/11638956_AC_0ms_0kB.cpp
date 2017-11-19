#include <bits/stdc++.h>

using namespace std;

char mp[1004][1004];
bool vis[1005][1004];
int n,m,flag;
int mov[][2]={0,1,0,-1,1,0,-1,0};

void dfs(int x,int y){
    if(flag)return;
    if(x==n-1){
        flag=1;
        return;

    }
    for(int i=0;i<4;i++){
        int xx =x+mov[i][0],yy=y+mov[i][1];
        if(xx<0||yy<0||yy>=m||xx>=n||vis[xx][yy]||mp[xx][yy]=='1')continue;
        vis[xx][yy]=1;
        dfs(xx,yy);
    }
}


int main(){

    while(cin>>n>>m){
        for(int i=0;i<n;i++)scanf("%s",mp[i]);
        memset(vis,0,sizeof(vis));
        flag=0;
        for(int i=0;i<m;i++){
            if(flag)break;
            if(!vis[0][i]&&mp[0][i]!='1')dfs(0,i);
        }
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}
