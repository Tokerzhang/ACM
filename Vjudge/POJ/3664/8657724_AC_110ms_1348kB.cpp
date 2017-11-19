#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXN 52000
using namespace std;
int a[MAXN],b[MAXN];
struct date
{
    int a;
    int b;
    int i;
} c[MAXN];
int cmp(date a,date b)
{
    return a.a>b.a;
}
int cmp2(date a,date b)
{
    return a.b>b.b;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&c[i].a,&c[i].b);
        c[i].i=i+1;
    }
    sort(c,c+n,cmp);
    sort(c,c+k,cmp2);
    cout<<c[0].i<<endl;
    return 0;
}
