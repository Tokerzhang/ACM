#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1010
#define lch(i) ((i)<<1)
#define rch(i) ((i)<<1|1)

double pos[2*N];
struct segment
{
    double l,r,h;
    int v;
}s[2*N];
struct node
{
    int l,r,cnt;
    double s,ss;
    int mid()
    { return (l+r)>>1; }
}t[2*N*4];
int n;

int cmp(struct segment p ,struct segment q)
{
    return p.h<q.h;
}

void build(int l ,int r ,int rt)
{
    t[rt].l=l; t[rt].r=r;
    t[rt].cnt=t[rt].s=t[rt].ss=0;
    if(l==r) return ;
    int mid=t[rt].mid();
    build(l,mid,lch(rt));
    build(mid+1,r,rch(rt));
}

int binarysearch(double key ,int low ,int high)
{
    while(low <= high)
    {
        int mid=(low+high)>>1;
        if(pos[mid] == key) 
            return mid;
        else if(pos[mid] < key) 
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

void cal(int rt)
{
    if(t[rt].cnt)
        t[rt].s = pos[t[rt].r+1] - pos[t[rt].l];
    else if(t[rt].l == t[rt].r)
        t[rt].s=0;
    else 
        t[rt].s = t[lch(rt)].s + t[rch(rt)].s;
/**************************************************/
    if(t[rt].cnt > 1)
        t[rt].ss = pos[t[rt].r+1] - pos[t[rt].l];
    else if(t[rt].l == t[rt].r)
        t[rt].ss = 0;
    else if(t[rt].cnt == 1)
        t[rt].ss = t[lch(rt)].s + t[rch(rt)].s;
    else
        t[rt].ss = t[lch(rt)].ss + t[rch(rt)].ss;
}

void updata(int l , int r ,int v ,int rt)
{
    if(t[rt].l==l && t[rt].r==r)
    {
        t[rt].cnt += v;
        cal(rt);
        return ;
    }
    int mid=t[rt].mid();
    if(r<=mid)     updata(l,r,v,lch(rt));
    else if(l>mid) updata(l,r,v,rch(rt));
    else
    {
        updata(l,mid,v,lch(rt));
        updata(mid+1,r,v,rch(rt));
    }
    cal(rt);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int i,k;
        for(i=0,k=0; i<n; i++,k+=2)
        {
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            pos[k]=x1; pos[k+1]=x2;
            s[k].l=x1;   s[k].r=x2;   s[k].h=y1;   s[k].v=1;
            s[k+1].l=x1; s[k+1].r=x2; s[k+1].h=y2; s[k+1].v=-1;
        }
        sort(pos,pos+k);
        sort(s,s+k,cmp);
        int m=1;
        for(i=1; i<k; i++)
            if(pos[i]!=pos[i-1])
                pos[m++]=pos[i];

        build(0,m-1,1);
        double res=0;
        for(i=0; i<k-1; i++)
        {
            int l=binarysearch(s[i].l,0,m-1);
            int r=binarysearch(s[i].r,0,m-1)-1;
            updata(l,r,s[i].v,1);
            res += t[1].ss*(s[i+1].h - s[i].h);
        }
        printf("%.2lf\n",res);
    }
    return 0;
}