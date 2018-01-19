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
const int MAXN = 200010;
struct Node{
    int l,r,ma;
}node[MAXN<<2];
int a[MAXN];
void init(int k,int l,int r){
    node[k].l=l;
    node[k].r=r;
    if(l==r){
        node[k].ma=a[l];
        return;
    }
    int mid = (l+r)>>1;
    init(k<<1,l,mid);
    init(k<<1|1,mid+1,r);
    node[k].ma=max(node[lson].ma,node[rson].ma);
}
int qurry(int k,int x,int y){
    if(node[k].l>y||node[k].r<x)return -10000;
    if(node[k].l>=x&&node[k].r<=y){
        return node[k].ma;
    }
    return max(qurry(k<<1,x,y),qurry(k<<1|1,x,y));
}
void update(int k,int p,int v){
    if(node[k].l==node[k].r&&node[k].l==p){
        node[k].ma=v;
        return;
    }
    if(node[k].l<=p&&node[k].r>=p){
        update(lson,p,v);
        update(rson,p,v);
        node[k].ma = max(node[lson].ma,node[rson].ma);
    }
}
int main() {
    int n,m;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            //cin>>a[i];
            scanf("%d",&a[i]);
        }
        init(1,1,n);
        for(int i=0;i<m;i++){
            char s[2];
            int x,y;

            getchar();
            scanf("%s %d%d",&s,&x,&y);
            //cin>>s>>x>>y;
            if(s[0]=='Q'){
                cout<<qurry(1,x,y)<<endl;
            }else{
                update(1,x,y);
            }
        }
    }
    return 0;
}