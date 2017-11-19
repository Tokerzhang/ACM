#include <bits/stdc++.h>

using namespace std;
vector<int> v;

int main() {
    double t1,t2,h1,h2;
    while (cin >> h1>>t1>>h2>>t2) {
        double c=sqrt(h1/h2);
        printf("%.6f\n",(c*t2-t1)/(c-1));
    }
    return 0;
}