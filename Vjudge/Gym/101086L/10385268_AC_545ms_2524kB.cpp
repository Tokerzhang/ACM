#include <bits/stdc++.h>

using namespace std;

int a[120000];
int b[1200];
int prime[120];
int main() {
    prime[2]=1,prime[3]=1,prime[5]=1,prime[7]=1,prime[11]=1,prime[13]=1;
    for(int i=1;i<120000;i++)
    {
        int cnt=0;int t=i;

        while(t){
            if(t%2==1)cnt++;
            t/=2;
        }
        a[i]=a[i-1]+prime[cnt];
        //cout<<a[i]<<endl;
    }
    int t;
    cin >> t;
    b[1]=1;
    while (t--) {
        int l,r;
        cin>>l>>r;

        cout<<a[r]-a[l-1]<<endl;
    }
}