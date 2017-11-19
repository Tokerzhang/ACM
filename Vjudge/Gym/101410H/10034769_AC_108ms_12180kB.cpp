
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200010;
const int INF = 1000010000;
#define sc(x) scanf("%d",&x)
#define lowbit(x) (x&-x)
#define scll(x) scanf("%lld",&x)
#define mem(a,v) memset(a,v,sizeof(v));
#define FOR(x,y,z) for(int x=y;x<=z;x++)
const int MOD = int(1e9) + 7;
int n,m;
int nxt[maxn];
int idx[maxn];
int pos[maxn];
vector<int> vt[maxn];
bool vis[maxn];
int is[maxn];
int desk[maxn];
void dfs(int tt,int x,int d)
{
    if(vis[x])return;
    vis[x]=1;
    pos[x]=d;
    idx[x]=tt;
    vt[tt].push_back(x);
    dfs(tt,nxt[x],d+1);
}

int main()
{
    freopen("kids.in","r",stdin);
    freopen("kids.out","w",stdout);
    sc(n),sc(m);
    for(int i=1,x,y; i<=n; i++)
    {
        sc(x),sc(y);
        is[i]=x;
        desk[x]=i;
        nxt[x]=y;
    }
    for(int i=1; i<=n; i++)if(!vis[i])dfs(i,i,0);

    for(int i=1; i<=m; i++)
    {
        int x,y;
        sc(x),sc(y);
        x=is[x];
        int len=vt[idx[x]].size();
        int px=pos[x];
        px+=y;
        px%=len;
        printf("%d\n",desk[vt[idx[x]][px]]);
    }
    fclose(stdin);
    fclose(stdout);
}
