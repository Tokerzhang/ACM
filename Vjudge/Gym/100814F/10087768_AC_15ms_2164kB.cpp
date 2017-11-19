#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=10100;
int  a[MAXN],b  [MAXN];
int kmpnext[MAXN];
int n,m;


int main()
{
    int t;
    cin>>t;

    while(t--){
        int a,b;
        cin>>a>>b;
        if(a==b)cout<<"Square"<<endl;
        else cout<<"Rectangle"<<endl;
    }
}
