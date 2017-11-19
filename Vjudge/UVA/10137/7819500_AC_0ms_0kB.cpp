#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            return 0;
        double a[n],ave=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&a[i]);
            ave+=a[i];
        }
        ave=round(ave/n*100)/100;
        double sum1,sum2;
        sum1=sum2=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<ave)sum1+=ave-a[i];
            else
                sum2+=a[i]-ave;
        }
        printf("$%.2f\n",(sum1<sum2)?sum1:sum2);
    }
    return 0;
}