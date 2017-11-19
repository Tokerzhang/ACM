#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int x=0,y=1023;
int fun(int u,int i) {
    if(u&(1<<i)) return 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,a;
    cin>>n;
    string s;
    for(int i=0;i<n;++i) {
        cin>>s>>a;
        if(s[0]=='|') {x|=a; y|=a;}
        if(s[0]=='^') {x^=a; y^=a;}
        if(s[0]=='&') {x&=a; y&=a;}

    }
    int i=0,v1=0,v2=0;
    while(i<=10) {
        if(!fun(x,i) && fun(y,i)) v1+=(1<<i);
        if(fun(x,i) && fun(y,i)) v2+=(1<<i);
        if(fun(x,i) && !fun(y,i)) {
            v1+=(1<<i);
            v2+=(1<<i);
        }
        ++i;
    }
    cout<<2<<endl<<"& "<<v1<<endl<<"^ "<<v2<<endl;
    return 0;
}