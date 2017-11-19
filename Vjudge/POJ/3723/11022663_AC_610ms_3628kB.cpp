#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int maxn = 500200;
int n,m,r;
int f[maxn];
struct edge
{
    int u,v,w;
    edge(int _u,int _v,int _w):u(_u),v(_v),w(_w)
    {}
};
vector<edge>v;
int vis[maxn];
void init(int n)
{
    memset(vis,0,sizeof(vis));
    v.clear();
    for(int i=0; i<=n; i++)
    {
        f[i]=i;
    }
}
int find(int x)
{
    return (x==f[x])?x:f[x]=find(f[x]);
}
int marge(int x,int y)
{
    int tx=find(x);
    int ty= find(y);
    if(tx==ty)
    {
        return 0;
    }
    f[tx]=ty;
    return 1;
}
bool cmp(edge a,edge b)
{
    return a.w>b.w;
}
int krusal()
{
    sort(v.begin(),v.end(),cmp);
    int ret =0;
    for(int i=0; i<v.size(); i++)
    {
        if(marge(v[i].u,n+v[i].v))
        {
            ret+=v[i].w;
        }
    }
    return ret;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>r;
        init(n+m+10);
        for(int i=0,a,b,c; i<r; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            v.push_back(edge(a,b,c));
        }

        cout<<(n+m)*10000-krusal()<<endl;
    }

    return 0;
}
