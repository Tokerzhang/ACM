#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int y,Y,i;
double f,w;

int main()
{
    while(1==scanf("%d",&y)&&y)
    {
        w=log(4);
        for(Y=1960;Y<=y;Y+=10)
        {
            w*=2;
        }
        i=1;
        f=0;
        while(f<w)
        {
            f+=log((double)++i);
        }
        printf("%d\n",i-1);
    }
    return 0;
}
