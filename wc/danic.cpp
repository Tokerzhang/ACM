#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000;
const int inf = 0x3f3f3f3f;
char s[100][100];
char ss[100][100];

struct Edge {
    int from, to, cap, flow;
    Edge() {}
    Edge(int f, int t, int c, int fl) { from = f, to = t, cap = c, flow = fl; }
};

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int cur[maxn];
    int dep[maxn];
    bool vis[maxn];

    void init(int n, int s, int t) {
        this->n = n;
        this->s = s;
        this->t = t;
        edges.clear();
        for (int i = 0; i < n; ++i)
            G[i].clear();
    }

    void addedge(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool bfs() {
        queue<int> q;
        while (!q.empty()) q.pop();
        memset(vis, false, sizeof vis);
        vis[s] = true;
        dep[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < G[u].size(); ++i) {
                Edge e = edges[G[u][i]];
                int v = e.to;
                if (!vis[v] && e.cap > e.flow) {
                    vis[v] = true;
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return vis[t];
    }

    int dfs(int x, int mi) {
        if (x == t || mi == 0) return mi;
        int flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); ++i) {
            Edge &e = edges[G[x][i]];
            int y = e.to;
            if (dep[y] == dep[x] + 1 && (f = dfs(y, min(mi, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                mi -= f;
                if (mi == 0) break;
            }
        }
        return flow;
    }

    int max_flow() {
        int ans = 0;
        while (bfs()) {
            memset(cur, 0, sizeof cur);
            ans += dfs(s, inf);
        }
        return ans;
    }
} dinic;

int full_flow;

bool check(int x, int y, int i, int j, int d) {
    if (abs(x - i) + abs(y - j) <= d) return true;
    else return false;
}


int main() {
    int n, m, src, dst, d;
    while (cin >> n >> m >> d) {
        full_flow = 0;
        for (int i = 1; i <= n; ++i)
            scanf("%s", s[i] + 1);
        int len = strlen(s[1] + 1);
        m = len;
        src = 0;
        dst = 2 * n * m + 1;
        dinic.init(2 * n * m + 2, src, dst);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= len; ++j) {
                if (s[i][j] - '0' > 0) {
                    int id = (i - 1) * m + j;
                    dinic.addedge(id, id + n * m, s[i][j] - '0');
                    if (i <= d || i + d > n || j <= d || j + d > m) {//这个点能直接跳出去
                        dinic.addedge(id + n * m, dst, inf);
                    } else {
                        for (int x = 1; x <= n; ++x) {
                            for (int y = 1; y <= m; ++y) {
                                if (x == i && y == j) continue;
                                if (check(x, y, i, j, d)) {
                                    int id2 = (x - 1) * m + y;
                                    dinic.addedge(id + n * m, id2, inf);//这个点的出连向能到达点的入

                                }
                            }
                        }
                    }
                }

            }
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%s", ss[i] + 1);
            for (int j = 1; j <= len; ++j) {
                if (ss[i][j] == 'L') {
                    full_flow++;
                    int id = (i - 1) * m + j;
                    dinic.addedge(src, id, 1);
                }
            }
        }
        int ans = full_flow - dinic.max_flow();
        if (ans == 0) printf("0\n");
        else if (ans == 1) printf("1\n");
        else printf("%d\n", ans);
    }
    return 0;
}
