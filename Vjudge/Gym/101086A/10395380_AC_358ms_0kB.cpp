#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int x,n;
        char c;
        ll l=0,r=1ll<<60;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %c",&x,&c);
            if(c=='-')r=min(r,l+x+24);
            else l+=x+25;
        }
        cout<<r-l+1<<endl;
    }
}
