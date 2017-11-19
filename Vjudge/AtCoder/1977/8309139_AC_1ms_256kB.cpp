#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#define MAXN 10200
#define EPS 1E-7

using namespace std;
int a[MAXN];
int main()
{
    int a=0,b=0,c;
    for(int i=0;i<3;i++)
    {
        cin>>c;
        if(c==5)
            a++;
        if(c==7)
            b++;

    }
    if(a==2&&b==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
