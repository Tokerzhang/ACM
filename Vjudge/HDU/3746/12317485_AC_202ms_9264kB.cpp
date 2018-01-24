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
char s[100010];

int main() {
    int T;
    cin>>T;
    while(T--){
        scanf("%s",&s);
        int len = strlen(s);
        //cout<<s<<endl;
        preKMP(s,len,kmpnext);
        int nextlen = kmpnext[len];
        if(kmpnext[len]==0)
        {
            printf("%d\n",len);
            continue;
        }
        if(len%(len-nextlen)==0){
            cout<<"0"<<endl;
        }else{
            cout<<len-nextlen-len%(len-nextlen)<<endl;
        }
    }
    return 0;
}
