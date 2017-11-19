#include <bits/stdtr1c++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;

        int flag=0;
        for(int i=0,t;i<n;i++)
        {
            cin>>t;
            if(!(t%(n*(n-1))>=1&&t%(n*(n-1))<n))flag=1;
        }
        if(flag)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}