#include <bits/stdtr1c++.h>
using namespace std;
int A[11];
void init()
{
    A[0]=1;
    for(int i=1;i<=10;i++)
    {
        A[i]=A[i-1]*i;
    }
    A[0]=0;
}

int main()
{
    init();
    int t;
    scanf("%d",&t);
    while(t--){

        char num[12];
        int ans=0;
        scanf("%s",&num);
        int len = (int)strlen(num);
        if(len ==1){
            printf("%.9f\n",0.);
            continue;
        }
        for(int i=0;i<len;i++){
            int cnt=0;
            for(int j=i+1;j<len;j++)
            {
                if(num[j]<num[i])cnt++;
            }
            ans+=A[len-i-1]*cnt;
        }
        ans = A[len]-ans -1;
        if(ans ==0){
            printf("%.9f\n",0.0);
            continue;
        }
        double base =1.0/A[len];
        double pre=base*pow((1+base),ans-1);

        printf("%.9f\n",pre);


    }
}