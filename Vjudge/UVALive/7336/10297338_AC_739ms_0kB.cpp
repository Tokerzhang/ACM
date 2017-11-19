#include<cstdio>
#include<vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>
#include <map>
#define Fopen freopen("in.txt","r",stdin)

using namespace std;
struct date{
    int d,s;
    char r;
}a[50010];
const int maxn=100010;
bool cmp(date a,date b)
{
    return  a.d<b.d;
}
int sum[20];
void add(int x)
{
    for(int i=x+1;i<=10;i++)
    {
        sum[i]++;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(sum,0,sizeof(sum));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d %c",&a[i].d,&a[i].s,&a[i].r);
        }
        sort(a,a+n,cmp);
        int cnt=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i].r=='c'&&a[i].s==1)ans+=sum[a[i].d];
           if(a[i].r=='i'&&a[i].s==0)add(a[i].d);
        }
        cout<<ans<<endl;

    }
    return 0;
}
