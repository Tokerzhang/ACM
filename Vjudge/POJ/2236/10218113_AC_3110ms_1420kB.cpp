#include<cstdio>
#include<cmath>
#include<cstring>

const double esp = 1e-7;
const int maxn = 1000+10;

int p[maxn]; //父节点
bool used[maxn]; //标记改点是否修理
bool map[maxn][maxn]; //标记连通性

struct Point
{
    double x, y;
}point[maxn];

int find(int x)
{
    return x == p[x] ? x : p[x] = find(p[x]);
}

void Union(int x, int y)
{
    int fx = find(x);
    int fy = find(y);

    if(fx == fy) return;

    p[fx] = fy; //随意
}
double dist(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    int n, d;
    while(scanf("%d%d", &n, &d) != EOF)
    {
        memset(map, false, sizeof(map));
        memset(used, false, sizeof(used));

        for(int i = 1; i <= n; i++)
        {
            scanf("%lf%lf", &point[i].x, &point[i].y);
        }

        for(int i = 1; i <= n; i++)
        {
            p[i] = i;
            map[i][i] = true;
            for(int j = i+1; j <= n; j++)
            {
                if(dist(point[i], point[j])-d < esp)
                {
                    map[i][j] = true; //在距离范围内
                    map[j][i] = true;
                }
            }
        }

        char c;
        int x, y;
        getchar();
        while(scanf("%c", &c) != EOF)
        {
            if(c == 'O')
            {
                scanf("%d%*c", &x);
                if(!used[x]) //以前未被修理
                {
                    for(int i = 1; i <= n; i++) //依次判断
                    {
                        if(used[i] && map[i][x]) Union(x, i);
                    }
                    used[x] = true;
                }
            }
            else if(c == 'S')
            {
                scanf("%d%d%*c", &x, &y);
                if(find(x) == find(y)) printf("SUCCESS\n"); //连通
                else printf("FAIL\n"); //不连通
            }
        }
    }
    return 0;
}