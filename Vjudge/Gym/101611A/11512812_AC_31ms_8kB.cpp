#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,k;
ll check(ll a,ll b){
    if(a<=0||b<=0)return -1;
    ll t=0;
    while(a*3<=n){
        ++t;
        a*=2;
    }
    ++t;
    while(b<(n-a)){
        b*=2;
        ++t;
    }
    return t;
}
int main(){
    while(cin>>n>>k){
        int minn=-1;
        for(int i=1;i<k;i++){
            ll temp=check(i,k-i);
            if(minn==-1||minn>temp){
                minn=temp;
            }
        }
        cout<<minn<<endl;

    }
}
