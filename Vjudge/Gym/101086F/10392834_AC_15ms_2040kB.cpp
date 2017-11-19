#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define maxn 11
char s[maxn];
int T, num[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(num, 0, sizeof(num));
        scanf("%s", s);
        int can = 0;
        for (int i = 0; i < 7; i++)num[s[i] - 'A' + 1]++;
        for (int i = 1; i <= 5; i++)
            if (!num[i])can = 1;
        if (can) {
            for (int i = 0; i < 7; i++)
                for (int j = i + 1; j < 7; j++) {
                    int a = s[i] - 'A' + 1, b = s[j] - 'A' + 1, flag = 1;
                    num[a]--, num[b]--, num[a + b]++;
                    for (int k = 1; k <= 5; k++)
                        if (!num[k])flag = 0;
                    if (flag)can = 0;
                    num[a]++, num[b]++, num[a + b]--;
                }
            if (can) {
                for (int i = 0; i < 7; i++)
                    for (int j = i + 1; j < 7; j++)
                        for (int ii = 0; ii < 7; ii++)
                            for (int jj = ii + 1; jj < 7; jj++)
                                if (i != ii && i != jj && j != ii && j != jj) {
                                    int a = s[i] - 'A' + 1, b = s[j] - 'A' + 1, c = s[ii] - 'A' + 1, d =
                                            s[jj] - 'A' + 1, flag = 1;
                                    num[a]--, num[b]--, num[a + b]++;
                                    num[c]--, num[d]--, num[c + d]++;
                                    for (int k = 1; k <= 5; k++)
                                        if (!num[k])flag = 0;
                                    if (flag)can = 0;
                                    num[a]++, num[b]++, num[a + b]--;
                                    num[c]++, num[d]++, num[c + d]--;
                                }
            }
        }
        printf("%s\n", can ? "NO" : "YES");
    }
    return 0;
}