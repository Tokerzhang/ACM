#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=10100;
int get(int a,int b)
{
    int  cnt =0;
    int x=max(a,b);
    int y=min(a,b);
    a=x,b=y;
    while(a&&b)
    {
        if(a%2!=b%2)cnt++;
        a/=2,b/=2;
    }
    while(a){
        if(a%2==1)cnt++;

        a/=2;
    }
    return  cnt ;
}
int a[10000];
int main()
{
    int t;
    cin>>t;

    while(t--){
        int n,b;
        cin>>n;
        int ans=0;
        for(int i=0,ans=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ans=max(ans,get(a[i],a[j]));
            }
        }
        cout<<ans<<endl;
    }
}
