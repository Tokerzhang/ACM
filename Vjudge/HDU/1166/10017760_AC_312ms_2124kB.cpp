#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 102000;
const int INF = 1000010000;
#define sc(x) scanf("%d",&x)
#define lowbit(x) (x&-x)
#define scll(x) scanf("%lld",&x)
#define mem(a,v) memset(a,v,sizeof(v));
#define FOR(x,y,z) for(int x=y;x<=z;x++)
const int MOD = int(1e9) + 7;
int n,a[maxn],c[maxn];

void update(int x, int v) {
    while (x <= n) {
        c[x] += v;
        x += (x&-x);
    }
}

ll query(int x) {
    ll sum = 0;
    while (x > 0) {
        sum += c[x];
        x -= (x&-x);
    }
    return sum;
}

int main()
{
    int T,i,j,cas=1,xx;
    sc(T);
    while(T--){
        memset(c, 0, sizeof(c));
        cin>>n;
        char com[10];
        cout<<"Case "<<cas++<<":"<<endl;

        FOR(i,1,n){ sc(xx);update(i,xx);}
        //FOR(i,0,n){ cout<<query(i)<<endl;}
        char str[10];
        while (scanf("%s", str) != EOF)
        {
            if (str[0] == 'E') {
                break;
            }
            int a, b;
            scanf("%d%d", &a, &b);
            if (str[0] == 'A') {
                update(a, b);
            } else if (str[0] == 'S') {
                update(a, -b);
            } else {
                printf("%d\n", query(b) - query(a - 1));
            }
        }
    }
    return 0;
}