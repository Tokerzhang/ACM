#include <bits/stdc++.h>

using namespace std;
const int maxn = 205;
vector<pair<int, int> > eage[maxn];

int n, m;
int d[maxn], inq[maxn];

void init() {
    for (int i = 0; i < maxn; i++)eage[i].clear();
    for (int i = 0; i < maxn; i++)inq[i] = 0;
    for (int i = 0; i < maxn; i++)d[i] = 1e9;
}

int main() {
    while (cin >> n >> m) {
        init();
        for (int i = 0; i < m; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            eage[x].push_back(make_pair(y, z));
            eage[y].push_back(make_pair(x, z));
        }
        int s, t;
        scanf("%d%d",&s,&t);
        queue<int> que;
        que.push(s), d[s] = 0, inq[s] = 1;
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            inq[now] = 0;
            for (int i = 0; i < eage[now].size(); i++) {
                int v = eage[now][i].first;
                if (d[v] > d[now] + eage[now][i].second) {
                    d[v] = d[now] + eage[now][i].second;
                    if (inq[v] == 1)continue;
                    inq[v] = 1;
                    que.push(v);
                }
            }
        }
        if (d[t] == 1e9)cout<<-1<<endl;
        else cout << d[t] << endl;
    }
    return 0;
}
