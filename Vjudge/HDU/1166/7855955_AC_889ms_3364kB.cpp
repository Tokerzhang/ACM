#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAXN 50100
#define ll __int64
#define INF 0x7fffffff
#define L(u) (u<<1)
#define R(u) (u<<1|1)
#define eps 1e-8
typedef long long LL;
using namespace std;
int n,a[MAXN];
struct nodes
{
    int left,right,date;
}node[MAXN*4];

void Pushup(int u)
{
    node[u].date = node[L(u)].date + node[R(u)].date;
    return ;
}

void Build (int u,int left,int right)
{
    node[u].left = left,node[u].right = right;

    if (node[u].left == node[u].right)
    {
        node[u].date = a[left];
        return ;
    }
    int mid = (node[u].left + node[u].right)>>1;
    Build (L(u),left,mid);
    Build (R(u),mid+1,right);
    Pushup(u);
}

void Update(int u,int pos,int add)
{
    if (node[u].left==node[u].right)
    {
        node[u].date += add;
        return ;
    }
    int mid = (node[u].left + node[u].right)>>1;
    if (pos <= mid) Update(L(u),pos,add);
    else Update(R(u),pos,add);
    Pushup(u);
}

int Query(int u,int left,int right)
{
    if(node[u].left >= left && node[u].right <= right)
        return node[u].date;
    int mid=(node[u].left+node[u].right)>>1;
    if(right <= mid)
        return Query(L(u),left,right);
    else if(left > mid)
        return Query(R(u),left,right);
    else
        return Query(L(u),left,mid) + Query(R(u),mid+1,right);

}

int main()
{
    int cnt = 0,t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d:\n",++cnt);
        for(int i = 1; i <= n; i++)
            cin>>a[i];
        Build(1,1,n);
         int a,b;
            char q[10];
         while(1)
        {
            
            cin>>q;
            if(q[0] == 'A')
            {
                cin>>a>>b;
                Update(1,a,b);
            }
            else if(q[0] == 'S')
            {
                cin>>a>>b;
                Update(1,a,-b);
            }
            else if(q[0] == 'Q')
            {
                cin>>a>>b;
                cout<<Query(1,a,b)<<endl;
            }
            else
            {
                break;
            }

        }
    }
    return 0;
}
