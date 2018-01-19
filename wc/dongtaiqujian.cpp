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

#define lson k<<1
#define rson k<<1|1
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 200010, INF = 1000000000;
#define MAXN 1000100
using namespace std;
int in[MAXN];
int ansmin = INF, ansmax = -INF;

struct Segment_tree {
    struct node {
        int l, r;
        int num;
        int minn;
        int maxx;
    };
    node tree[MAXN * 4];

    void init(int n) {
        memset(tree, 0, sizeof tree);
        for (int i = 0; i <= n << 2; i++)
            tree[i].minn = INF, tree[i].maxx = -INF;
    }

    void build(int left, int right, int k) {
        tree[k].l = left;
        tree[k].r = right;
        if (left == right) {
            tree[k].maxx = tree[k].minn = in[left];
            tree[k].num = 1;
            return;
        }
        int mid = (left + right) >> 1;
        build(left, mid, k << 1);
        build(mid + 1, right, k << 1 | 1);
        tree[k].num = tree[k << 1].num + tree[k << 1 | 1].num;
        tree[k].minn = min(tree[k << 1].minn, tree[k << 1 | 1].minn);
        tree[k].maxx = max(tree[k << 1].maxx, tree[k << 1 | 1].maxx);
    }

    void query(int left, int right, int k) {
        if (left == 1 && (right == tree[k].num)) {
            ansmin = min(ansmin, tree[k].minn);
            ansmax = max(ansmax, tree[k].maxx);
            return;
        }
        int n1 = tree[k << 1].num;
        int n2 = tree[k << 1 | 1].num;
        if (left <= n1 && right > n1) {
            query(left, n1, k << 1);
            query(1, right - n1, k << 1 | 1);
        } else if (left <= n1 && right <= n1) query(left, right, k << 1);
        else if (left > n1 && right <= n1 + n2) query(left - n1, right - n1, k << 1 | 1);
    }

    void del(int num, int root) {
        if ((tree[root].l == tree[root].r)) {
            tree[root].num--;
            tree[root].minn = INF, tree[root].maxx = -INF;
            return;
        }
        int n1 = tree[root << 1].num;
        int n2 = tree[root << 1 | 1].num;
        if (num <= n1) del(num, root << 1);
        else del(num - n1, root << 1 | 1);
        tree[root].num = tree[root << 1].num + tree[root << 1 | 1].num;
        tree[root].minn = min(tree[root << 1].minn, tree[root << 1 | 1].minn);
        tree[root].maxx = max(tree[root << 1].maxx, tree[root << 1 | 1].maxx);
    }
} S;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    S.init(n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &in[i]);
    S.build(1, n, 1);
    for (int i = 1; i <= m; i++) {
        int a;
        scanf("%d", &a);
        if (a == 1) {
            int temp;
            scanf("%d", &temp);
            S.del(temp, 1);
        } else if (a == 2) {
            int tep1, tep2;
            ansmin = INF, ansmax = -INF;
            scanf("%d%d", &tep1, &tep2);
            S.query(tep1, tep2, 1);
            printf("%d %d\n", ansmin, ansmax);
        }
    }
    return 0;
}
