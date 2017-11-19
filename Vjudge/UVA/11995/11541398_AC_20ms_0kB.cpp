#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

queue<int>q;
stack<int>s;
priority_queue<int>pq;

int main() {
    int n;
    int op,num;
    while(cin>>n) {
        while(!q.empty())q.pop();
        while(!s.empty())s.pop();
        while(!pq.empty())pq.pop();
        bool isq=1;
        bool iss=1;
        bool ispq=1;
        while(n--) {
            cin>>op>>num;
            if(op==1) {
                if(isq)
                    q.push(num);
                if(iss)
                    s.push(num);
                if(ispq)
                    pq.push(num);
            } else if(op==2) {
                if(isq) {
                    if(q.empty())
                        isq=0;
                    else {
                        if(q.front()!=num) {
                            isq=0;
                        } else {
                            q.pop();
                        }
                    }
                }
                if(iss) {
                    if(s.empty())
                        iss=0;
                    else {
                        if(s.top()!=num) {
                            iss=0;
                        } else {
                            s.pop();
                        }
                    }
                }
                if(ispq) {
                    if(pq.empty())
                        ispq=0;
                    else {
                        if(pq.top()!=num) {
                            ispq=0;
                        } else {
                            pq.pop();
                        }
                    }
                }

            }
        }
        if(iss && !isq && !ispq)
            printf("stack\n");
        else if(!iss && isq && !ispq)
            printf("queue\n");
        else if(!iss && !isq && ispq)
            printf("priority queue\n");
        else if(!iss && !isq && !ispq)
            printf("impossible\n");
        else
            printf("not sure\n");

    }
    return 0;
}
