#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int a,b,vis[8000];
int f(int l,int r)
{
    for(int i=l;i<=r;i++)
    {

    }
}
int n=1827,t[200001];//num:原数组；t：树状数组
int lowbit(int x)
{
    return x&(-x);
}
void change(int x,int p)//将第x个数加p
{
    while(x<=n)
    {
        t[x]+=p;
        x+=lowbit(x);
    }
    return;
}
int sum(int k)//前k个数的和
{
    int ans=0;
    while(k>0)
    {
        ans+=t[k];
        k-=lowbit(k);
    }
    return ans;
}
int ask(int l,int r)//求l-r区间和
{
    return sum(r)-sum(l-1);
}
int main() {
    int n;
    while(cin>>n)
    {
        memset(vis,0,sizeof(vis));
        memset(t,0,sizeof(t));
        for(int i=0,a,b;i<n;i++)
        {
            cin>>a>>b;
            for(int j=a;j<=b;j++)
            {
                if(!vis[j]){
                    vis[j]=1;
                    change(j,1);
                }
            }
        }
        int flag=0;
        for(int i=1;i+179<=1826;i++)
        {
            //cout<<ask(i,i+179)<<endl;
            if(ask(i,i+179)>90){
                flag=1;
            }
        }
        if(flag)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}