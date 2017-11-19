#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,k;
int a[120000];
unsigned long long b[20];
int main() {
    b[0]=1;
    for(int i=1; i<=9; i++)b[i]=b[i-1]* (128);
    while(cin>>n) {

        for(int i=1; i<=n; i++)cin>>a[i];
        for(int i=1; i<=n; i++) {
            unsigned long long ans =0;
            int j;
            for(j=i; a[j]>=128; j++) {
                ans+=(ll)(a[j]-128)*b[j-i];
            }
            ans+=(ll)(a[j])*b[j-i];
            i=j;
            ll t=ans/2;
            if(ans%2==1){
                cout<<-1-t<<endl;
            }else
                cout<<t<<endl;

        }
    }
}
