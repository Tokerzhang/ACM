#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define mod 9875321
#define pi acos(-1)
#define inf 1000000000
#define ul unsigned long long
#define ll long long
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,cir,cnt;
int fa[100005];
int u[10005],v[10005];
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main()
{
    while(1)
    {
        memset(fa,0,sizeof(fa));
        n=m=cir=cnt=0;
        while(1)
        {
            int a=read(),b=read();
            fa[a]=a;fa[b]=b;
            if(a==0)break;
            u[++m]=a;v[m]=b;
            if(a==-1)return 0;
        }
        for(int i=1;i<=100000;i++)
            if(fa[i]==i)n++;
        for(int i=1;i<=m;i++)
        {
            int p=find(u[i]),q=find(v[i]);
            if(p==q)cir=1;
            else fa[p]=q,cnt++;
        }
        if(!cir&&(cnt==n-1||n==0))puts("Yes");
        else puts("No");
    }
    return 0;
}