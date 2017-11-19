# include <stdio.h>
# include <string.h>
int main()
{
    int n, i, sum, icount, flag, a[27];
    char c;
    while(~scanf("%d",&n))
    {
        getchar();
        sum = icount = 0;
        memset(a, 0, sizeof(a));
        for(i=0; i<n; ++i)
        {
            c = getchar();
            a[c-'a']++;
        }
        do
        {
            flag = 0;//控制字串连续的开关
            for(i=0; i<27; ++i)
            {
                if(a[i])
                {
                    if(flag)
                    {
                        --a[i];
                        ++icount;//记录减去的字母数，等于n时退出循环
                    }
                    else
                    {
                        flag = 1;
                        --a[i];
                        ++icount;
                        ++sum;//记录连续的字串数
                    }
                }
                else
                    flag = 0;
            }
        }
        while(icount != n);
        printf("%d\n",sum);
    }
    return 0;
}
