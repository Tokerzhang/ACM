/*
2017年8月27日10:54:52
Gym-100543H 
代码参考@Preludes
AC 

*/ 
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector> 
using namespace std;
const int maxn=15;
int c[maxn][maxn];
int f[310];
bool vis[310];
int k;
//判断该数字是否合法  
bool judge(int x){
	int tot=0;
	int a[10];
	for(;x;x/=10){
		a[++tot]=x%10;
	}
	for(int i=tot;i>1;i--){
		if(!c[a[i]][a[i-1]]) return false;
	}
	return true;
}

void init(){
	for(int i=0;i<=9;i++) c[1][i]=1;
	/*列出所有合法的形式，用于判断该数字是否合法*/ 
	c[2][2]=1;
	c[2][3]=1;
	c[2][5]=1;
	c[2][6]=1;
	c[2][8]=1;
	c[2][9]=1;
	c[2][0]=1;
	
	c[3][3]=1;
	c[3][6]=1;
	c[3][9]=1;
	
	c[4][4]=1;
	c[4][5]=1;
	c[4][6]=1;
	c[4][7]=1;
	c[4][8]=1;
	c[4][9]=1;
	c[4][0]=1;
	
	c[5][5]=1;
	c[5][6]=1;
	c[5][8]=1;
	c[5][9]=1;
	c[5][0]=1;
	
	c[6][6]=1;
	c[6][9]=1;
	
	c[7][7]=1;
	c[7][8]=1;
	c[7][9]=1;
	c[7][0]=1;
	
	c[8][8]=1;
	c[8][9]=1;
	c[8][0]=1;
	
	c[9][9]=1;
	
	c[0][0]=1;
	
	memset(vis,false,sizeof(vis));
	memset(f,-1,sizeof(f));
	/*题目保证输入不会大于200，我们多算一点到300*/ 
	for(int i=0;i<=300;i++){
		if(judge(i)) vis[i]=1;
	}
	/*把每个数字左右两边依次判断，
	即+0 +1 +2，……+300  -0 -1 -2 -3 ，……，-300
	以及是否合法，找到第一个满足条件的退出这层循环，找下一个数*/ 
	for(int i=1;i<=200;i++){
		for(int j=0;j<=300;j++){
			if(i-j>=0&&vis[i-j]){
				f[i]=i-j;break;
			}
			if(i+j<=300&&vis[i+j]){
				f[i]=i+j;break;
			}
		}
	}
}




int main(){
	int t;
	scanf("%d",&t);
	init();
	while(t--){
		scanf("%d",&k);
		printf("%d\n",f[k]); 	
	} 
	return 0;
} 
