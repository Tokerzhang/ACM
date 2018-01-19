#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
//#include <map>
#include <string>
#include <cstring>

using namespace std;

const double EPS = 1e-5;
const int MAXN = 1100;

int n;
int map[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int a){
    for(int i=0;i<n;i++){
        if(map[a][i]&&!used[i]){
            used[i]=true;
            if(linker[i]==-1||dfs(linker[i])){
                linker[i]=a;
                return true;
            }
        }
    }
    return false;
}
int hungary(){
    int result = 0;
    memset(linker,-1, sizeof(linker));
    for(int i=0;i<n;i++){
        memset(used,0, sizeof(used));
        if(dfs(i))result++;
    }
    return result;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        int num,a,b;
        memset(map,0,sizeof(map));
        for(int i=1;i<=n;i++)
        {
            scanf("%d: (%d)",&a,&num);
            for(int j=0;j<num;j++)
            {
                scanf("%d",&b);
                map[a][b]=1;
            }
        }
        int cnt = hungary();
        printf("%d\n",n-cnt/2);
    }
    return 0;
}