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

void preKMP(char x[], int m, int kmpNext[]) {
    int i, j;
    j = kmpNext[0] = -1;
    i = 0;
    while (i < m) {
        while (-1 != j && x[i] != x[j])j = kmpNext[j];
        if (x[++i] == x[++j])kmpNext[i] = kmpNext[j]; else kmpNext[i] = j;
    }
}

int kmpnext[100010];
char s[100010], t[100010];

int kmp_count(char x[], int m, char y[], int n) {
    int i, j,ans=0;
    preKMP(x, m, kmpnext);
    i = j = 0;
    while (i < n) {
        while (-1 != j && y[i] != x[j])j = kmpnext[j];
        i++;
        j++;
        if (j >= m) {
            ans++;
            j = 0;
        }
    }
    return ans;
}

int main() {
    while (1) {
        scanf("%s %s", &s, &t);
        if (s[0] == '#')break;
        int len = strlen(s);
        cout<<kmp_count(t,strlen(t),s,strlen(s))<<endl;
    }
    return 0;
}
