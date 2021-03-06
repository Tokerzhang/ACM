#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

char s1[N], s2[N];
int l[N][N];
int l1, l2;

void init () {

    memset (l, 0, sizeof (l));
    l1 = strlen(s1);
    l2 = strlen(s2);
}

int Max (const int a, const int b) { return a > b? a: b; }

int main () {

    while (gets(s1) != NULL) {

        gets (s2);
        init ();

        for (int i = 1; i <= l1; i++)
            for (int j = 1; j <= l2; j++)
                if (s1[i - 1] == s2[j - 1])
                    l[i][j] = l[i - 1][j - 1] + 1;
                else
                    l[i][j] = Max (l[i][j - 1], l[i - 1][j]);
        printf ("%d\n", l[l1][l2]);
    }
    return 0;
}

