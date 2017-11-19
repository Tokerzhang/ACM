#include<stdio.h>
#include<string.h>
#define N 1000
int p[N]={0};
int find(int x)
{
	//return x==p[x]?x:p[x]=find(p[x]);
	while(x!=p[x])
	x=p[x];
	return x;
}
int fun(int x,int y)
{
	int fy,fx;
	fy=find(y);
	fx=find(x);
	if(fy!=fx)
	{
		p[fy]=fx;
	}
}
int main()
{
	int k,i,a,b,flag;
	int sum;
	k=1;
	while(1)
	{
		flag=0;
		while(scanf("%d %d",&a,&b)!=EOF&&a&&b)
		{
			if(a==-1||b==-1)
			return 0;
			if(p[a]==0) p[a]=a;
			if(p[b]==0) p[b]=b;
			if(find(a)==find(b)) flag=1;
			if(flag!=1)
			fun(a,b);
		}
		for(i=1,sum=0;i<=N;i++)
		{
			if(p[i]==i) sum++;
			p[i]=0;
		}
		if(sum>1||flag==1)
		printf("Case %d is not a tree.\n",k);
		else printf("Case %d is a tree.\n",k);
		k++;
	}
	return 0;
}