#include <bits/stdc++.h>

#define pii pair<int,int>
#define pdd pair<double,double>
#define scan(_int) scanf("%d",&_int)
#define scan2(_int, __int) scanf("%d%d",&_int,&__int)
using namespace std;
typedef long long ll;
const int maxn = 50010;
int n, m, head[maxn], tot;

struct Edge {
    int v, next;
} edge[maxn * 2];
int pre[maxn], lowlink[maxn], sccno[maxn];
int ind[maxn], outd[maxn];

int dfs_clock, scc_cnt;

stack<int> S;

void dfs(int u) {
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);

    for (int i = head[u]; i != -1; i=edge[i].next) {
        int v = edge[i].v;
        if (!pre[v]) {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        } else if (!sccno[v]) {
            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }
    if (lowlink[u] == pre[u]) {
        scc_cnt++;
        for (;;) {
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            if (x == u)break;
        }

    }
}

void find_scc(int n) {
    dfs_clock = scc_cnt = 0;
    memset(sccno, 0, sizeof(sccno));
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i < n; i++) {
        if (!pre[i])
            dfs(i);
    }
    //cout<<"xx";
}

void addedge(int u, int v) {
    edge[tot].v = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void init() {
    tot = 0;
    memset(edge,0,sizeof(edge));
    memset(head, -1, sizeof(head));
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        init();
        cin >> n >> m;
        for (int i = 0, u, v; i < m; i++) {
            scan2(u, v);
            u--, v--;
            addedge(u, v);
        }

        find_scc(n);

        for (int i = 1; i <= scc_cnt; i++) {
            ind[i] = outd[i] = 1;
        }
        for (int u = 0; u < n; u++) {
            for (int i = head[u]; i != -1; i = edge[i].next) {

                int v = edge[i].v;
                if (sccno[u] != sccno[v]) {
                    ind[sccno[v]] = outd[sccno[u]] = 0;
                }
            }
        }
        int a = 0, b = 0;
        for (int i = 1; i <= scc_cnt; i++) {
            if(ind[i])a++;
            if(outd[i])b++;
        }
        int ans = max(a,b);
        //cout<<scc_cnt;
        if(scc_cnt==1)
            ans=0;
        printf("%d\n",ans);
    }
    return 0;
}
