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
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 200010, INF = 1000000000;

int n,q,a[maxn];

struct Node{
    int l,r;
    int max,min;
}node[maxn<<2];

void build(int k,int l,int r){
    node[k].l=l,node[k].r=r;
    if(l==r){
        node[k].min=node[k].max=a[l];
        return;
    }
    int mid = (node[k].l+node[k].r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    node[k].max=max(node[lson].max,node[rson].max);
    node[k].min=min(node[lson].min,node[rson].min);
}

int qurry_max(int k,int l,int r){
    if(node[k].l==l&&node[k].r==r){
        return node[k].max;
    }
    int mid=(node[k].l+node[k].r)>>1;
    if(r<=mid)return qurry_max(lson,l,r);
    else if(l>mid)return  qurry_max(rson,l,r);
    else{
        return max(qurry_max(lson,l,mid),qurry_max(rson,mid+1,r));
    }
}
int qurry_min(int k,int l,int r){
    if(node[k].l==l&&node[k].r==r){
        return node[k].min;
    }
    int mid=(node[k].l+node[k].r)>>1;
    if(r<=mid)return qurry_min(lson,l,r);
    else if(l>mid)return  qurry_min(rson,l,r);
    else{
        return min(qurry_min(lson,l,mid),qurry_min(rson,mid+1,r));
    }
}

int main(){
    while(scanf("%d%d",&n,&q)!=EOF){

        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        build(1,1,n);
        for(int i=0,l,r;i<q;i++){
            scanf("%d%d",&l,&r);
            cout<<qurry_max(1,l,r)-qurry_min(1,l,r)<<endl;
        }
    }
    return 0;
}