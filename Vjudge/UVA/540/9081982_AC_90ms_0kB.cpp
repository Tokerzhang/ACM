#include <bits/stdc++.h>

using namespace std;
const int maxn = 1020;

int main() {
    int t, time = 0;
    while (cin >> t && t) {
        printf("Scenario #%d\n", ++time);
        map<int, int> team;

        for (int i = 0; i < t; i++) {
            int n, x;
            scanf("%d", &n);
            while (n--) {
                scanf("%d", &x);
                team[x] = i;
            }
        }

        queue<int> q, q2[maxn];
        while (1) {
            int x;
            char cmd[10];
            cin >> cmd;
            if (cmd[0] == 'S')break;
            else if (cmd[0] == 'D') {

                printf("%d\n", q2[q.front()].front());

                q2[q.front()].pop();

                if (q2[q.front()].empty())q.pop();
            
            } else if (cmd[0] == 'E') {
                
                scanf("%d", &x);
                int t = team[x];
                if(q2[t].empty()) q.push(t);
                q2[t].push(x);
            }
        }
        cout<<endl;
    }


    return 0;
}

