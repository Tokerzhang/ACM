#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#define MAXN 1200
using namespace std;
char s[MAXN];

int main() {
    cin>>s;
    int len = strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]==',')
            putchar(' ');
        else
            putchar(s[i]);
    }
    cout<<endl;
    return 0;

}