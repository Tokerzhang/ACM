#include<cstdio>
#include<vector>
#include <string>
#include <iostream>
#include <cstring>
#include <map>
#define Fopen freopen("in.txt","r",stdin)

using namespace std;
const int maxn=100010;
int day[20]={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31};
map<string,int>week;
int main()
{
    week["SUN"]=1;
    week["MON"]=2;
    week["TUE"]=3;
    week["WED"]=4;
    week["THU"]=5;
    week["FRI"]=6;
    week["SAT"]=7;

    week["JAN"]=1;
    week["FEB"]=2;
    week["MAR"]=3;
    week["APR"]=4;
    week["MAY"]=5;
    week["JUN"]=6;
    week["JUL"]=7;
    week["AUG"]=8;
    week["SEP"]=9;
    week["OCT"]=10;
    week["NOV"]=11;
    week["DEC"]=12;
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        int ans =0,cnt=week[b];
        for(int i=1;i<=day[week[a]];i++) {
            if (cnt == 6 || cnt == 7)ans++;
            cnt++;
            if (cnt > 7)
            cnt = 1;
        }
        cout<<ans<<endl;
    }

    return 0;
}
