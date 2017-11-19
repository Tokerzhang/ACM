#include <iostream>
#include <algorithm>

#define MAXN 5000
using namespace std;
int n, l;
int a[MAXN], b[MAXN];
int ta[MAXN], tb[MAXN];

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n - 1; i++) {
        ta[i] = a[i + 1] - a[i];
    }

    ta[n - 1] = a[0] + l - a[n - 1];

    for (int i = 0; i < n - 1; i++) {
        tb[i] = b[i + 1] - b[i];
    }
    tb[n - 1] = b[0] + l - b[n - 1];
    /*for(int i=0;i<n;i++){
        cout<<ta[i]<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<tb[i]<<endl;
    }*/
    for (int i = 0; i <= n; i++) {
        int flag = 1;

        for (int j = 0; j < n; j++) {
            if (i+j < n) {
                //cout<<ta[i]<<tb[j]<<endl;
                if (ta[i+j] != tb[j]) {
                    flag = 0;
                    break;
                }
            }
            if (i+j >= n) {
                //cout<<ta[i+j-n]<<tb[j]<<endl;
                if (ta[i+j - n] != tb[j]) {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag) {
            cout << "YES" << endl;
            return 0;
        }

    }
    cout << "NO" << endl;
    return 0;
}