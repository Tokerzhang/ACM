#include <bits/stdc++.h>

using namespace std;
const int maxn =4005*100,sigma_size=26;
int ch[maxn][sigma_size];
bool vis[maxn];
int nd_cnt;
void init(){nd_cnt=1;memset(ch[0],0,sizeof(ch[0]));}
void add(char *s){
    int u=0;
    for(int i=0;s[i];i++){
        int c =s[i]-'a';
        if(!ch[u][c]){
            memset(ch[nd_cnt],0,sizeof(ch[nd_cnt]));
            vis[nd_cnt]=false;
            ch[u][c]=nd_cnt++;
        }
        u=ch[u][c];
    }
    vis[u]=true;
}
const int LEN = 3e5+10,mod=20071027;
char str[LEN];
int d[LEN];

int main(){
    char word[120];
    int ks=0;
    while(gets(str)){
        init();
        int S;cin>>S;
        getchar();
        while(S--)
        {

            gets(word);
        //cout<<S<<" "<<word<<endl;
            add(word);
        }
        int n=0;
        while(str[n])d[n++]=-1;
        d[n]=1;
        for(int cur = n-1;cur>=0;cur--){
            int u=0;d[cur]=0;
            for(int i=cur;i<n;i++){
                int c=str[i]-'a';
                if(!ch[u][c])break;
                u=ch[u][c];
                if(vis[u])d[cur]+=d[i+1];
            }
            d[cur]%=mod;
        }
        printf("Case %d: %d\n",++ks,d[0]);
    }
    return 0;
}
