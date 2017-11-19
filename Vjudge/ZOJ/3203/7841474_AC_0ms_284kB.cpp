#include <iostream>
#include <stdio.h>
using namespace std;
const double eps=1e-9;
double D,H,h,l,r;

double equ(double x)
{
    return D-x+H-(H-h)*D/x;
}

double ternarysearch(double l,double r)
{
    double ans1,ans2;
    while(r-l>eps)
    {
        double ll=(l+l+r)/3;
        double rr=(l+r+r)/3;
         ans1=equ(ll);
         ans2=equ(rr);
        if(ans1>=ans2)
        r=rr;
        else
        l=ll;
    }
    return ans1;
}

int main()
{int t;
 cin>>t;
 while(t--)
 {
     cin>>H>>h>>D;
     l=(H-h)*D/H;//相似
     r=D;
     double ans=ternarysearch(l,r);
     printf("%.3lf\n",ans);
 }
    return 0;
}