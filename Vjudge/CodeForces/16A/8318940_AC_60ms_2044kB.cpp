#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>

#define MAXN 4050
using namespace std;
typedef long long ll;



bool result(int n,int m,char map[105][105])
{
	for(int i=0;i<n;++i)
	{
		if(map[i][0]==map[i+1][0])
		{
			return false;
		}
		for(int j=1;j<m;++j)
		{
			if(map[i][j]!=map[i][j-1])
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		char map[105][105]={0};
		for(int i=0;i<n;++i)
		{
			scanf("%s",map[i]);
		}
		printf("%s\n",result(n,m,map)?"YES":"NO");
	}
	
} 