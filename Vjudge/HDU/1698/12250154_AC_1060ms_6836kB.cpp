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
const int maxn = 100010, INF = 1000000000;


struct Node {
    int l, r;
    int sum, tag;
    int lazy;
} node[maxn << 2];

void init(int k, int l, int r) {
    node[k].l = l;
    node[k].r = r;
    node[k].lazy = 0;
    node[k].tag = 0;
    if (l == r) {
        node[k].sum = 1;
        return;
    }
    int mid = (l + r) >> 1;
    init(lson, l, mid);
    init(rson, mid + 1, r);
    node[k].sum = node[lson].sum + node[rson].sum;
}

void update(int k, int l, int r, int c) {
    if (node[k].l == l && node[k].r == r) {
        node[k].lazy = true;
        node[k].tag = c;
        node[k].sum = (r-l + 1) * c;
        return;
    }
    int mid = (node[k].l + node[k].r) >> 1;
    if (node[k].lazy==1) {
        node[k].lazy = false;
        update(lson, node[k].l, mid, node[k].tag);
        update(rson, mid + 1, node[k].r, node[k].tag);
        node[k].tag = 0;
    }

    if (r <= mid)update(lson, l, r, c);
    else if (l > mid)update(rson, l, r, c);
    else {
        update(lson, l, mid, c);
        update(rson, mid + 1, r, c);
    }
    node[k].sum = node[lson].sum + node[rson].sum;
}

int main() {
    int n, q;
    int T;
    cin >> T;
    int ks=0;
    while (T--) {
        cin >> n >> q;
        init(1, 1, n);

        for (int i = 0, x, y, z; i < q; i++) {
            scanf("%d%d%d", &x, &y, &z);
            update(1, x, y, z);
        }
        printf("Case %d: The total value of the hook is %d.\n",++ks,node[1].sum);
    }

    return 0;
}
