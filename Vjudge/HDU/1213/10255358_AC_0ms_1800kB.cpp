#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
const int maxn = 30010;
int n,m,f[maxn];
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
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        init(n);
        for(int i=0,a,b;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            marge(a,b);
        }
        set<int>Set;
        for(int i=1;i<=n;i++)
        {
            if(f[i]==i)Set.insert(i);
        }
        cout<<Set.size()<<endl;
    }
    return 0;
}
