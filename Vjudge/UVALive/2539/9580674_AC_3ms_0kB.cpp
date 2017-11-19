#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int inf = ( 1 << 20 ) ;
int p[27]; struct prog {
    int u;
    int v;
    int w;
}map[80];
bool cmp ( prog a , prog b)
{
    return a.w<b.w;
}
int find(int x)
{
    return x==p[x]?x:p[x]=find(p[x]);
}
int main()
{
    int n;
    while ( cin >> n , n )
    {
        int i , j ;
        for  ( i = 0 ; i < 27  ; i ++ )
            p[i] = i ;
        int k = 0 ;
        for ( i = 0 ; i < n - 1 ; i ++ )
        {
            char str[3];
            int m;
            cin >> str >> m ;
            for ( j = 0 ; j < m ; j ++ ,k ++ )
            {
                char str2[3];
                int t;
                cin >> str2 >> t ;
                map[k].u=(str[0]-'A');
                map[k].v=(str2[0]-'A');
                map[k].w=t;
            }
        }

        sort ( map , map + k , cmp );
        int ans=0;
        for ( i = 0 ; i < k ; i ++ )
        {
            int x = find(map[i].u);
            int y = find(map[i].v);
            if( x!=y)
            {
                ans+=map[i].w;
                p[x]=y;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
