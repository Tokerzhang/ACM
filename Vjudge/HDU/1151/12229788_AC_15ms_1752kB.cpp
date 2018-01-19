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
const int maxn = 200;
bool vis[maxn],mp[maxn][maxn];
int link[maxn];
int n,m;
bool dfs(int u){
    for(int i=1;i<=n;i++){
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
    for(int i=1;i<=n;i++){
        memset(vis, false, sizeof(vis));
        if(dfs(i))ans++;
    }
    cout<<n-ans<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(link,-1, sizeof(link));
        memset(mp, false, sizeof(mp));
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            //if(b==0||c==0)continue;
            mp[a][b]= true;
        }
        solve();
    }
    return 0;
}