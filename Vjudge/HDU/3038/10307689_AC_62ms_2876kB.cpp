#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n,m,f[maxn],ran[maxn];
void init()
{
    for(int i=0;i<=n;i++)
    {
        f[i]=i;ran[i]=0;
    }
}
int find(int x)
{
    if(f[x]==x){
        return x;
    }
    int par=f[x];
    f[x]=find(f[x]);
    ran[x]+=ran[par];
    return f[x];
}

bool marge(int x,int y,int c)
{
    int tx=find(x),ty=find(y);
    if(tx==ty)
    {
        if(ran[x]+c!=ran[y])return false;
        return true;
    }
    f[ty]=tx;
    ran[ty]=ran[x]-ran[y]+c;
    return true;
}
int main()
{
    int a,b,c;
    while (scanf("%d%d",&n,&m)!=EOF) {
        int cnt=0;
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);

            if(!marge(a-1,b,c))cnt++;
        }
        cout<<cnt<<endl;
    }

}
