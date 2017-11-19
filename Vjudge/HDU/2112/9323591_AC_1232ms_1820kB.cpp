

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define Max 155

int dis[Max], res[Max][Max];
bool visit[Max];

void Dijkstra(int start, int end)
{
    int temp, k;
    memset(visit, false, sizeof(visit));
    for(int i = 1; i <= end; ++i)
        dis[i] = res[start][i];
    dis[start] = 0;
    visit[start] = 1;
    for(int i = 1; i <= end; ++i)
    {
        temp = INF;
        for(int j = 1; j <= end; ++j)
            if(!visit[j] && temp > dis[j])
                temp = dis[k = j];
        if(temp == INF) break;
        visit[k] = 1;
        for(int j = 1; j <= end; ++j)
            if(!visit[j] && dis[j] > dis[k] + res[k][j])
                dis[j] = dis[k] + res[k][j];
    }
}

int main()
{
    int num, count;
    char s[32], e[32];
    bool flag;
    char str[32], str1[32];
    int cost;
    map<string, int>car;
    while(scanf("%d", &num) != EOF && num != -1)
    {
        flag = 0;
        car.clear();
        memset(res, INF, sizeof(res));
        count = 3;
        scanf("%s%s", s, e);
        if(strcmp(s, e) == 0)
            flag = 1;
        car[s] = 1;
        car[e] = 2;
        for(int i = 1; i <= num; ++i)
        {
            scanf("%s%s%d", str, str1, &cost);
            if(!car[str])
                car[str] = count++;
            if(!car[str1])
                car[str1] = count++;
            if(cost < res[car[str]][car[str1]])
                res[car[str]][car[str1]] = res[car[str1]][car[str]] = cost;
        }
        if(flag)
        {
            printf("0\n");
            continue;
        }
        Dijkstra(1, count - 1);
        if(dis[2] == INF)
            printf("-1\n");
        else
            printf("%d\n", dis[2]);
    }
    return 0;
}
