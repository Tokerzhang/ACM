#include <iostream>
#include <cstdio>
#include <algorithm>
#define FOR(x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
const int INF = 1<<31;
const int maxn = 3e5+10;

int f[maxn],a[maxn];
void init(int n)
{
	for(int i = 0;i <= n;i++)
		f[i]=i;
}
int find(int x)
{
	return (x==f[x])?x:f[x]=find(f[x]);
}
void marge(int x,int y)
{
	int u=find(x);
	int v=find(y);
	f[u]=v;
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0)break;
		init(n);
		int t,T,x,y;
		while (m--)
		{
			x=-1;
			cin>>t;
			while(t--)
			{
				scanf("%d", &y);
				if(x==-1)x=y;

				marge(x,y);

			}
		}
		int book = find(0);
		int cnt = 0;
		for(int i=0;i<=n;i++)
		{
				if(find(i)==book)++cnt;
		}
		printf("%d\n", cnt);
	}


}
