    #include"stdio.h"  
    #include"vector"  
    #include"string.h"  
    #define N 100100  
    using namespace std;  
    vector <int>g[N];  
    int c[N];  
    int main()  
    {  
        int T,a,b,n,m,q,op,i;  
        scanf("%d",&T);  
        while(T--)  
        {  
            scanf("%d%d",&n,&m);  
            for(i=0;i<=n;i++)                 //清空容器  
                g[i].clear();  
            while(m--)  
            {  
                scanf("%d%d",&a,&b);  
                g[b].push_back(a);          //输入数据，感觉就是一个二维数组   
                g[a].push_back(b);  
            }  
            scanf("%d",&q);  
            memset(c,0,sizeof(c));  
            while(q--)  
            {  
                scanf("%d",&op);  
                if(op==0)  
                {  
                    scanf("%d%d",&a,&b);  
                    c[a]+=b;  
                }  
                else  
                {  
                    int s=0;  
                    scanf("%d",&a);  
                    for(i=0;i<g[a].size();i++)                //对数据的访问也很方便  
                    {  
                        s+=c[g[a][i]];  
                    }  
                    printf("%d\n",s);  
                }  
            }  
        }  
        return 0;  
    }  


