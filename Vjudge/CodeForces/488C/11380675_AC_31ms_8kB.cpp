#include<bits/stdc++.h>
using namespace std;
#define maxn 205
#define inf 999999.9
int main()
{
    int h1,h2,a1,a2,d1,d2,ph,pa,pd,i,j,k;
    cin>>h1>>a1>>d1>>h2>>a2>>d2>>ph>>pa>>pd;
    a1-=d2;a2-=d1;
    k=99999999;
    for(i=0;i<=200;i++)
        for(j=0;j<=100;j++)if(a1+i>0)k=min(k,pa*i+pd*j+ph*max(0,((h2-1)/(a1+i)+1)*max(0,a2-j)-h1+1));
    cout<<k;
    return 0;
}