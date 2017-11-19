#include <bits/stdtr1c++.h>
using namespace std;
int n[15]= {1,1};
int a[15];
double p,q;
void init()
{
    for(int i=2; i<11; i++)
    {
        n[i]=n[i-1]*i;
    }

}
int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        string s;
        int cnt = 0;
        cin >> s;

        int l = s.length();
        for (int i = 0; i < l; i++) {
            a[i] = s[i] - '0';
        }
        while (next_permutation(a, a + l)) {
            cnt++;
        }
        if (cnt == 0) {
            printf("0.000000000\n");
            continue;
        }


        double temp = 1.0 / n[l];
        q = p = temp;
        for (int i = 1; i < cnt; i++) {
            q = p + p * temp;
            p = q;
        }
        printf("%.9lf\n", p);

    }
    return 0;
}
