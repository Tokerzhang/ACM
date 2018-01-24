#include <bits/stdc++.h>
#include <algorithm>

#define N 1002100
using namespace std;
typedef long long ll;


char s[N];
int fail[N];

int main() {
    int n;
    int ks = 0;
    while (scanf("%d",&n)!=EOF) {
        if(!n) return 0;
        scanf("%s", s);

        fail[1] = fail[1] = 0;
        for (int i = 1; i < n; i++) {
            int j = fail[i];
            while (j && s[i] != s[j])j = fail[j];
            fail[i + 1] = s[i] == s[j] ? j + 1 : 0;
        }

        printf("Test case #%d\n", ++ks);
        
        for (int i = 2; i <= n; i++) {
            if (fail[i] > 0 && i % (i - fail[i]) == 0)printf("%d %d\n", i, i / (i - fail[i]));
        }
        putchar('\n');
    }
}
