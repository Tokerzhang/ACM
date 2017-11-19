#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <list>
#define LL long long
#define eps 1e-8
#define maxn 101000
#define mod 100000007
#define inf 0x3f3f3f3f
#define mid(a,b) ((a+b)>>1)
#define IN freopen("in.txt","r",stdin);
using namespace std;

int cnt[100];

int main(int argc, char const *argv[])
{
    //IN;

    int n, m;
    int flag = 0;
    while(scanf("%d %d", &n,&m) != EOF)
    {
        memset(cnt, 0, sizeof(cnt));

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cnt[i+j]++;
            }
        }

        if(flag) printf("\n");
        flag = 1;

        int ma = 0;
        for(int i=0; i<=n+m; i++) ma = max(ma, cnt[i]);

        for(int i=0; i<=n+m; i++)
        {
            if(cnt[i] == ma)
                printf("%d\n", i);
        }
    }

    return 0;
}
