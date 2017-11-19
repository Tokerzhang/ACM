#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int ans=1;
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i==0)
            {
                n/=i;
                ans*=i-1;
                while(n%i==0)
                {
                    n/=i;
                    ans*=i;
                }
            }

        }
        if(n>1)
            cout<<ans*(n-1)/2<<endl;
        else
            cout<<ans/2<<endl;
    }

    return 0;
}
