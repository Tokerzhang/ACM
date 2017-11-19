#include <bits/stdc++.h>
using namespace std;

double f(double x){
    return 8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*x+6;
}
int main(){
    double l,r,mid,y;
    int k;
    scanf("%d",&k);
    while(k--){
        scanf("%lf",&y);
        l=1;r=100;
        if(y<f(0)||y>f(100)){
            printf("No solution!\n");
            continue;
        }
        while(r-l>1e-8){
            mid=(l+r)/2;
            if(f(mid)<y)    l=mid;
            else            r=mid;
        }
        printf("%.4f\n",l);
    }
    return 0;
}
 
