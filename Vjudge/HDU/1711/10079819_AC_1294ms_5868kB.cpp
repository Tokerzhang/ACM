#include<stdio.h>
#include<string.h>
#define N 1000005
int s[N];
int p[N];
int next[N];
int m,n;
void getnext(){
    int j=0,k=-1;
    next[0]=-1;
    while(j<m){
        if(k==-1||p[j]==p[k]){
            j++;
            k++;
            next[j]=k;
        }
        else
            k=next[k];
    }
}
int kmp(){
    int i=0,j=0;
    getnext();
    while(i<n){
        if(j==-1||s[i]==p[j]){
            i++;
            j++;
        }
        else
            j=next[j];
        if(j==m)
            return i-m+1;
    }
    return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)scanf("%d",&s[i]);
        for(int i=0;i<m;i++)scanf("%d",&p[i]);
        printf("%d\n",kmp());
    }
    return 0;
}
