#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 102000;
const int INF = 1000010000;
#define sc(x) scanf("%d",&x)
#define lowbit(x) (x&-x)
#define scll(x) scanf("%lld",&x)
#define mem(a,v) memset(a,v,sizeof(v));
#define FOR(x,y,z) for(int x=y;x<=z;x++)
const int MOD = int(1e9) + 7;
struct date{
    int king,q,b,k,r,p;//1 1 2 2 2 8
}chess1[2],chess2[2];
int king,q,b,k,r,p;
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);

    int k1,k2;
    sc(k1),sc(k2);
    string s1,s2;
    for(int i=0,x;i<k1;i++){
        cin>>s1>>s2;
        if(s1[0]=='b')x=0;
        else x=1;
        if(s2[0]=='k'&&s2[1]=='i')chess1[x].king++,king++;
        if(s2[0]=='k'&&s2[1]=='n')chess1[x].k++,k++;
        if(s2[0]=='q')chess1[x].q++,q++;
        if(s2[0]=='b')chess1[x].b++,b++;
        if(s2[0]=='r')chess1[x].r++,r++;
        if(s2[0]=='p')chess1[x].p++,p++;
    }
    for(int i=0,x;i<k2;i++){
        cin>>s1>>s2;
        if(s1[0]=='b')x=0;
        else x=1;
        if(s2[0]=='k'&&s2[1]=='i')chess2[x].king++;
        if(s2[0]=='k'&&s2[1]=='n')chess2[x].k++;
        if(s2[0]=='q')chess2[x].q++;
        if(s2[0]=='b')chess2[x].b++;
        if(s2[0]=='r')chess2[x].r++;
        if(s2[0]=='p')chess2[x].p++;
    }
    int flag=1;
    vector<string>ans;
    string T[2]={"black ","white "};
    for(int i=0;i<=1;i++){
        if(chess1[i].king+chess2[i].king>=1){
            for(int j=0;j<1-chess1[i].king;j++){
                ans.push_back(T[i]+"king");
            }
        }else{
            flag=0;break;
        }
        if(chess1[i].q+chess2[i].q>=1){
            for(int j=0;j<1-chess1[i].q;j++){
                ans.push_back(T[i]+"queen");
            }
        }else{
            flag=0;break;
        }
        if(chess1[i].b+chess2[i].b>=2){
            for(int j=0;j<2-chess1[i].b;j++){
                ans.push_back(T[i]+"bishop");
            }
        }else{
            flag=0;break;
        }
        if(chess1[i].k+chess2[i].k>=2){
            for(int j=0;j<2-chess1[i].k;j++){
                ans.push_back(T[i]+"knight");
            }
        }else{
            flag=0;break;
        }
        if(chess1[i].r+chess2[i].r>=2){
            for(int j=0;j<2-chess1[i].r;j++){
                ans.push_back(T[i]+"rook");
            }
        }else{
            flag=0;break;
        }
        if(chess1[i].p+chess2[i].p>=8){
            for(int j=0;j<8-chess1[i].p;j++){
                ans.push_back(T[i]+"pawn");
            }
        }else{
            flag=0;break;
        }
    }
    if(flag){
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<endl;
        }
    } else{
        cout<<"impossible"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}