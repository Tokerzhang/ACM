#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 30010;
int f[maxn];
int find(int x)
{
    return (f[x]==x)?x:f[x]=find(f[x]);
}
void marge(int x,int y)
{
    x=find(x);
    y=find(y);
    f[x]=y;
}
void init(int n)
{
    for(int i=0;i<=n;i++)f[i]=i;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        init(n);

        for(int i=0;i<m;i++)
        {
            int k,t;
            scanf("%d",&k);

            cin>>t;
            for(int i=1,a;i<k;i++){scanf("%d",&a);marge(t,a);}
        }
        int ans =0;
        for(int i=0;i<=n;i++)
        {
            if(find(0)==find(i))ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
