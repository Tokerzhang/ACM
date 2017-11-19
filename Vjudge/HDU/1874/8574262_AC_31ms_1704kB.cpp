#include <bits/stdc++.h>

#define MAXN 260
using namespace std;
typedef  long long ll;
int mp[MAXN][MAXN];


int main() {
    int n, m;
    while (scanf("%d %d", &n, &m)!=EOF) {

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)mp[i][j] = 1e9;
                else mp[i][j] = 0;


        int x, y, z;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d",&x,&y,&z);
            mp[x][y]=min(mp[x][y],z);
            mp[y][x]=min(mp[y][x],z);
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++){
                    mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
                }
        int s,t;
        cin>>s>>t;

        if(mp[s][t]==1e9)cout<<-1<<endl;
        else cout<<mp[s][t]<<endl;
    }

    return 0;
}
