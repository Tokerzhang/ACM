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
int n,m;
ll k;
ll dis[N],wisdom[N];
int vis[N];
vector<pair<int,pair<ll,ll> > >edg[N];
bool spfa(ll mid){
    for(int i=0;i<=n;i++)vis[i]=0,dis[i]=1e16;
    dis[1]=0;
    queue<int>q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=0; i<edg[u].size(); i++) {
            int v=edg[u][i].first;
            ll c=edg[u][i].second.first;
            ll w=edg[u][i].second.second;
            if(w>mid)continue;
            if(dis[v]>dis[u]+c) {
                dis[v]=dis[u]+c;
                if(!vis[v]) {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    if(dis[n]<k)return true;
    else return false;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%lld",&n,&m,&k);
        for(int i=1; i<=n; i++)edg[i].clear();
        for(int i=1,u,v; i<=m; i++){
            ll w,c;
            scanf("%d%d%lld%lld",&u,&v,&c,&w);
            edg[u].pb(mp(v,mp(c,w)));
            edg[v].pb(mp(u,mp(c,w)));
        }
        ll l=0,r=1e9,ans=-1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(spfa(mid))r=mid-1,ans=mid;
            else l=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}