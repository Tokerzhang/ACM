#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<math.h>
#include<map>
#include<queue> 
#include<algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
int num[55];//num[i]表示第i个串中最少需要移动的次数得到数字 
int zimu[55];//zimu[i]表示第i个串中最少需要移动的次数得到字母 
int fuhao[55];//fuhao[i]表示第i个串中最少需要移动的次数得到特殊符号 
int n,m;
string s[55]; 
int main ()
{
    while (cin>>n>>m){
        for (int i=0;i<55;i++){
            num[i]=zimu[i]=fuhao[i]=1e6;//一开始距离默认为无穷大 
        }
        for (int i=0;i<n;i++) {
            cin>>s[i];
        } 
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){//找数字，如果在第一个能找到 
                if (j==0&&s[i][j]<='9'&&s[i][j]>='0'){
                    num[i]=j;
                    break;
                }
                if (j!=0){//往两边找 
                    if ((s[i][j]<='9'&&s[i][j]>='0')||(s[i][m-j]<='9'&&s[i][m-j]>='0')){
                        num[i]=j;
                        break;
                    }
                }
            }
            for (int j=0;j<m;j++){//字母，同上 
                if (j==0&&s[i][j]<='z'&&s[i][j]>='a'){
                    zimu[i]=j;
                    break;
                }
                if (j!=0&&(s[i][j]<='z'&&s[i][j]>='a'||s[i][m-j]<='z'&&s[i][m-j]>='a')){
                    zimu[i]=j;
                    break;
                } 
            }
            for (int j=0;j<m;j++){//特殊符号，同上 
                if (j==0&&(s[i][j]=='#'||s[i][j]=='*'||s[i][j]=='&')){
                    fuhao[i]=j;
                    break;
                } 
                if (j!=0&&(s[i][j]=='#'||s[i][j]=='*'||s[i][j]=='&'||s[i][m-j]=='#'||s[i][m-j]=='*'||s[i][m-j]=='&')){
                    fuhao[i]=j;
                    break;
                } 
            }
        }
        int minx=inf;//找最小值，一开始默认为无穷大 
        for (int i=0;i<n;i++){//枚举所有情况 
            for (int j=0;j<n;j++){
                for (int k=0;k<n;k++){
                    if (i==j||i==k||k==j)continue;//三个串两两不能同一个串 
                    int tmp=num[i]+zimu[j]+fuhao[k];
                    minx=min(minx,tmp);
                }
            }
        }
        cout<<minx<<endl;
    }
    return 0;
}