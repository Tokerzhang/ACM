#include <bits/stdc++.h>

using namespace std;
int a, b;
char mp[3][12000];
int mov[8][2] = {{1,  0},
                 {1,  1},
                 {0,  1},
                 {1,  -1},
                 {0,  -1},
                 {-1, 0},
                 {-1, -1},
                 {1,  1}};;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        for (int i = 0; i < 3; i++) {
            scanf("%s", &mp[i]);
        }
        int ans = 0;
        for (int i = 0; i < 3*m; i ++) {
            if(mp[1][i]!='X')continue;
            int cnt = 0;

            for(int ii=i-1;ii<=i+1;ii++){
                if(mp[0][ii]=='*')cnt++;
                if(mp[1][ii]=='*')cnt++;
                if(mp[2][ii]=='*')cnt++;
            }
            ans= max(ans, cnt);

        }
        cout << ans * 4 << endl;
    }
}