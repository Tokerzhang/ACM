#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>

#define MAXN 20010
using namespace std;


int main() {
    int k, s;
    int a1, a2, cnt = 0;
    cin >> k >> s;
    {
        for (int i = 0; i <= k; i++) {
            int z = s - i;
            a1 = max(0, z - k);
            a2 = min(k, z);
            //cout<<a1<<" "<<a2<<"   ";
            if(a2-a1<0)
                continue;
            cnt += (a2-a1+1);
        }
        cout << cnt << endl;
    }
    return 0;
}
