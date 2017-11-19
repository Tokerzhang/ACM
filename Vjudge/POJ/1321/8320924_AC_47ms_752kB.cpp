#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 120
using namespace std;
int n,k,book[MAXN],cnt,sum;
char mp[MAXN][MAXN];

void dfs(int s){
    if(cnt == k)
    {
        sum++;
        return;
    }
    else{
        if(s>=n) return;
        else{
            for(int i=0;i<n;i++)
            {
                if(mp[s][i]=='#'&&!book[i]){
                    book[i]=1;
                    cnt++;
                    dfs(s+1);
                    cnt--;
                    book[i]=0;
                }
            }
        }
        dfs(s+1);
    }
}

int main()
{
    while(cin>>n>>k){
        //getchar();
        if(n==-1&&k==-1) break;
        memset(book,0,sizeof(book));
        for(int i=0;i<n;i++)
        {
            scanf("%s",mp[i]);
        }
        cnt=sum=0;
        dfs(0);
        cout<<sum<<endl;
    }
    return 0;
}