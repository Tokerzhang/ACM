#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define met(a,b) memset(a,b,sizeof a)
#define sys system("pause")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N = 5e5+5;
const int M = 2e5+50;
const int mod = 1e9+7;
int n,m,k;
ll mn[N];
vector<pair<int,ll> >edg[N];
vector<ll>vec;
void dfs(int u,ll tim){
    if(edg[u].size()==0)vec.pb(tim);
    for(int i=0; i<edg[u].size(); i++){
        
        int v=edg[u][i].first;
        ll w=edg[u][i].second;
        
        if(w==mn[u])dfs(v,tim+w/2);
        
        else dfs(v,tim+w-mn[u]/2);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        vec.clear();
        for(int i=1; i<=n; i++)edg[i].clear(),mn[i]=1e17;
        for(int i=2,v; i<=n; i++){
            ll w;
            scanf("%d%lld",&v,&w);
            edg[v].pb(mp(i,w*2));
            mn[v]=min(mn[v],w*2);
        }
        dfs(1,0);
        sort(vec.begin(),vec.end());
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            ll x;
            scanf("%lld",&x);
            int ans=upper_bound(vec.begin(),vec.end(),x)-vec.begin();
            printf("%d\n",ans);
        }
    }
    return 0;
}