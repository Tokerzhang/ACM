#include<bits/stdc++.h>

using namespace std;



map<int,vector<int> >mp;
int main() {
    int n,m;
    while(cin>>n>>m) {
        mp.clear();
        for(int i=1,num; i<=n; i++) {
            cin>>num;
            if(!mp.count(num))mp[num]=vector<int>();
            mp[num].push_back(i);
        }
        for(int i=0,v,k;i<m;i++){
            cin>>k>>v;
            if(k<=mp[v].size()&&mp.count(v))
                cout<<mp[v][k-1]<<endl;
            else{
                cout<<0<<endl;
            }

            }
    }
    return 0;
}
