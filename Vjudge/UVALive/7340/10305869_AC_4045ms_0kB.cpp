#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <fstream>
#define mx 20000002
#define mem(a) memset(a,0,sizeof(a))
using namespace std;
long num[20000005];
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    */
void get_num ()
{
    for(int i=2; i<mx; ++i)
        num[i]+=1+i;
    for(int i=2; i<mx; ++i)
        for(int j=2; i*j<mx; ++j)
            num[i*j]+=i;
    for(int i=3; i<mx; ++i)
        num[i]+=num[i-1];
}
int main()
{

    int n;
    mem(num);
    get_num();
    while(scanf("%d",&n),n)
        cout<<num[n]<<endl;
    return 0;
}
