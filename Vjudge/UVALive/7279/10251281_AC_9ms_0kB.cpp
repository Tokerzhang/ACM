#include<bits/stdc++.h>

using namespace std;

set<unsigned long long >s;

void create()
{
    for(int i=1; i<=63; i++) //m
    {
        for(int j=1; j<=63; j++) //n
        {
            for(int l=1; l<=64; l++)
            {
                if(!((l%(i+j)==0) || (l%(i+j)==i))) continue;
                unsigned long long temp=0,tt=1;
                int flag=1;
                int cnt = 0;
                while(1)
                {
                    if(cnt>=l)break;
                    if(flag)
                    {
                        temp<<=i;
                        flag=0;
                        cnt += i;
                        temp += (tt<<i)-1;


                    }
                    else
                    {
                        temp<<=j;
                        flag=1;
                        cnt+=j;
                    }
                }
                s.insert(temp);
            }
        }
    }
    return;
}

int main()
{
    create();
    unsigned long long x,y;
    while(cin>>x>>y)
    {
        int Ans = 0;

        set<unsigned long long >::iterator it;
        for(it=s.begin(); it!=s.end(); it++)
        {
            if((*it)>=x && (*it)<=y)
            {
                Ans++;
                //printf("%d\n", *it);
            }
        }
        cout<<Ans<<endl;
    }

    return 0;
}
