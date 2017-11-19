#include<cstdio>
#include<vector>
#include <string>
#include <iostream>
#include <cstring>
#include <map>
#define Fopen freopen("in.txt","r",stdin)

using namespace std;
const int maxn=100010;
int a[100];
int main()
{
    int t,ks=0;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            a[s[i]-'a']++;
        }
        int ans=999999999;
        for(int i=0;i<26;i++)
        {
            ans=min(a[i],ans);
        }
        cout<<"Case "<<++ks<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
