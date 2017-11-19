#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
using namespace std;
const int maxn=10100;

char ans[maxn];
set<char>w[maxn];
int main()
{
    int t;
    cin>>t;

    while(t--){
        
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)w[i].clear();
        
        for(int i=0;i<=n;i++)ans[i]='?';
    
        char a,b;
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf(" %c %c",&a,&b);
                if(b=='T')ans[j]=a;
                else w[j].insert(a);
                //cout<<a<<" "<<b<<endl;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(i!=1)putchar(' ');
            if(w[i].size()==3)
            {
                int a,b,c,d;
                a=b=c=d=0;
                for(set<char>::iterator j=w[i].begin();j!=w[i].end();j++)
                {
                    //cout<<*j<<endl;
                    if(*j=='A')a=1;
                    if(*j=='B')b=1;
                    if(*j=='C')c=1;
                    if(*j=='D')d=1;
                }
                if(!a)printf("A");
                if(!b)printf("B");
                if(!c)printf("C");
                if(!d)printf("D");

            }
            else
            {
                printf("%c",ans[i]);
            }

        }
        cout<<endl;
    }
}
