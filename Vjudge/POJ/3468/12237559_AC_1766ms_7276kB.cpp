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
typedef long long ll;
using namespace std;
typedef long long ll;
const int MAXN = 100100;
struct Node{
    int l,r;
    ll sum,lazy;
}node[MAXN<<2];
int a[MAXN];
void init(int k,int l,int r){
    node[k].l=l;
    node[k].r=r;
    node[l].lazy=0;

    if(l==r){
        node[k].sum=a[l];
        return;
    }
    int mid = (l+r)>>1;
    init(k<<1,l,mid);
    init(k<<1|1,mid+1,r);
    node[k].sum=(node[lson].sum+node[rson].sum);
}


void update(int k,int a,int b,ll add){
    if(node[k].l==a&&node[k].r==b){
        node[k].lazy+=add;
        return;
    }
    node[k].sum+=add*(b-a+1);
    int mid =(node[k].l+node[k].r)>>1;
    if(b<=mid)update(lson,a,b,add);
    else if(a>mid) update(rson,a,b,add);
    else{
        update(lson,a,mid,add);
        update(rson,mid+1,b,add);
    }

}
ll qurry(int k,int a,int b){
    if(node[k].l==a&&node[k].r==b){
        return node[k].sum+(b-a+1)*node[k].lazy;
    }
    node[k].sum+=(node[k].r-node[k].l+1)*node[k].lazy;
    int mid=(node[k].l+node[k].r)>>1;
    update(lson,node[k].l,mid,node[k].lazy);
    update(rson,mid+1,node[k].r,node[k].lazy);
    node[k].lazy=0;
    if(b<=mid)return qurry(lson,a,b);
    else if(a>mid)return qurry(rson,a,b);
    else
        return qurry(lson,a,mid)+qurry(rson,mid+1,b);
}

int main() {
    int n,m;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        init(1,1,n);
        char s[5];
        int x,y,t;
        for(int i=0;i<m;i++){

            //cin>>s>>x>>y;
            scanf(" %s %d%d",&s,&x,&y);
            if(s[0]=='Q'){
                cout<<qurry(1,x,y)<<endl;
            }else{
                scanf("%d",&t);
                update(1,x,y,t);
            }
        }

    }
    return 0;
}