#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <cstring>

using namespace std;
typedef long long ll;
const int maxn = 1200;
bool vis[maxn],mp[maxn][maxn];
int link[maxn];
int n,m,k;
bool dfs(int u){
    for(int i=1;i<n+m;i++){
        if(!vis[i]&&mp[u][i]){
            vis[i]=true;
            if(link[i]==-1||dfs(link[i])){
                link[i]=u;
                return true;
            }
        }
    }
    return false;
}
void solve(){
    int ans = 0;
    for(int i=1;i<n;i++){
        memset(vis, false, sizeof(vis));
        if(dfs(i))ans++;
    }
    cout<<ans<<endl;
}
int main() {
    while(cin>>n,n){
        cin>>m>>k;
        memset(link,-1, sizeof(link));
        memset(mp, false, sizeof(mp));
        for(int i=1;i<=k;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(b==0||c==0)continue;
            mp[b][c+n]= true;
        }
        solve();
    }
    return 0;
}