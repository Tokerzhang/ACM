#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#define MAXN 120
using namespace std;

int n,maxn=0,t,sum=0;

int main() {
	cin>>n;
	if(n<3)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>t;
		sum+=t;
		maxn=max(maxn,t);

		if(n>=3)
		{
			if(sum-maxn>maxn){
				cout<<i+1<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
    return 0;
}
