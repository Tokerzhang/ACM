#include <bits/stdc++.h>

using namespace std;
int a,b;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        a=max(a,b);
        cout<<a*a<<endl;
    }
}