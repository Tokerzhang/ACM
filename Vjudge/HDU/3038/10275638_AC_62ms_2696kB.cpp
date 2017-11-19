#include<cstdio>

const int N = 200005;
int n,m,f[N],rank[N];

inline void init(){
    for(int i=0; i<=n; ++i)
        f[i]=i,rank[i]=0;
}
int find(int x){
    if(x==f[x])return f[x];
    int fa=f[x];
    f[x] = find(f[x]);
    rank[x] += rank[fa];
    return f[x];
}
bool Union(int x,int y,int c){
    int a=find(x), b=find(y);
    if(a==b){
        if(rank[x]+c!=rank[y]) return false;
        return true;
    }
    f[b] = a;
    rank[b] = rank[x]-rank[y]+c;
    return true;
}
int main(){
    int a,b,c;
    while(~scanf("%d%d",&n,&m)){
        int cnt=0;
        init();
        for(int i=0; i<m; ++i){
            scanf("%d%d%d",&a,&b,&c);
            if(!Union(a-1,b,c)){
                ++cnt;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}