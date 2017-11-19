#include <bits/stdtr1c++.h>

using namespace std;

typedef long long ll;

int a[1200],b[1200];
int main(){
    int n;
    cin>>n;
    int day=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        if(day<a[i]){
            day=a[i];
            continue;
        } else if(day>=a[i]){
            int tmp=day-a[i];
            day=a[i]+b[i]*(tmp/b[i]+1);


        }

    }
    cout<<day<<endl;

}