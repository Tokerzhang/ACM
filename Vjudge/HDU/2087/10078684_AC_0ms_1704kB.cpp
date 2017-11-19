#include <bits/stdc++.h>

using namespace std;
const int maxn = 1200;
char s[maxn],t[maxn];
int kmpnext[maxn],n,m;

void getnext()
{
    kmpnext[0]=kmpnext[1]=0;
    for(int i=1;i<m;i++)
    {
        int j=kmpnext[i];
        while(j && t[i]!=t[j]) j=kmpnext[j];
        kmpnext[i+1] = (t[i]==t[j])?j+1:0;
    }
}
void kmp()
{
    n=strlen(s);
    m=strlen(t);
    getnext();
    int j=0;
    int cnt=0;
    int last;
    for(int i=0;i<n;i++)
    {
        while(j&&s[i]!=t[j])j=kmpnext[j];
        if(s[i]==t[j])j++;
        if(j==m)
        {
            if(cnt==0){
                cnt++;
                last=i;
            }
            else if(i-last>=m)
            {
                cnt++;
                last=i;
            }
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    while(scanf("%s", s)!=EOF)
    {
        if(s[0]=='#')break;
        scanf("%s", t);
        kmp();
    }

}
