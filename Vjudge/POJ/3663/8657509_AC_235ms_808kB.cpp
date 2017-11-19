#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int len[20200];

int main()
{
    int i,j,n,s,count;

    count=0;
    cin>>n>>s;
    for(i=0; i<n; i++)
        scanf("%d",&len[i]);
    sort(len,len+n);
    for(i=n-1; i>=0; i--)
    {
        if(len[i]<s)
        {
            for(j=i-1; j>=0; j--)
            {
                if(len[i]+len[j]<=s)
                {
                    count+=j+1;
                    break;
                }
            }
        }
    }
    printf("%d\n",count);

    return 0;
}
