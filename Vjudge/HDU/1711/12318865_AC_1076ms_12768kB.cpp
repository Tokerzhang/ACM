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
typedef long long ll;
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 300005, INF = 1000000000;

vector<int> col[maxn];
int a[maxn];

void preKMP(int x[], int m, int kmpNext[]) {
    int i, j;
    j = kmpNext[0] = -1;
    i = 0;
    while (i < m) {
        while (-1 != j && x[i] != x[j])j = kmpNext[j];
        if (x[++i] == x[++j])kmpNext[i] = kmpNext[j]; else kmpNext[i] = j;
    }
}

int kmpnext[1000100];
int s[1000100], t[1100000];

int kmp_count(int x[], int m, int y[], int n) {
    int i, j,ans=0;
    preKMP(x, m, kmpnext);
    i = j = 0;
    while (i < n) {
        while (-1 != j && y[i] != x[j])j = kmpnext[j];
        i++;
        j++;
        if (j >= m) {
            ans++;
            return i-m+1;
            j = kmpnext[j];
        }
    }
    return -1;
}

int main() {
    int T;
    cin>>T;
    while (T--) {
        int n,m;
        scanf("%d %d", &n, &m);
        for(int i=0;i<n;i++){
            scanf("%d",&s[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d",&t[i]);
        }
        cout<<kmp_count(t,m,s,n)<<endl;
    }
    return 0;
}
