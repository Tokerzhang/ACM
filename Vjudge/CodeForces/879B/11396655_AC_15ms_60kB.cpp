#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int a[12000];
int main(){
    ll n,k;
    cin>>n>>k;
    int maxn=-1000;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxn=max(a[i],maxn);
    }
    vector<int>v;
    for(int i=0;i<n;i++){
        v.push_back(a[i]);
    }

    if(k>=10*n){
        cout<<maxn<<endl;
    }else{
        int ans=0;
        int cnt=0;
        int tmp=v[0];
        for(int i=1;i<v.size();i++){
            if(cnt>=k){
                break;
            }

            if (tmp>v[i]){
                cnt++;
                v.push_back(v[i]);
                continue;
            }else {
                cnt = 1;
                v.push_back(tmp);
                tmp=v[i];
                continue;
            }
        }
        cout<<tmp<<endl;
    }


}
