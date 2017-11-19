#include<iostream>
#include<stack>
#define max 100
using namespace std;
int main()
{
    stack<char>s;
    int n,i,j,k,result[max];//n为列车个数， result数组用来表示结果，1表示进栈。0表示出
    char str1[max],str2[max];//序列1和序列2
    while(cin>>n>>str1>>str2)
    {
        j=0,i=0,k=1;
        s.push(str1[0]);//为防止栈空，压一个进去
        result[0]=1;//记录进来了一个。
        while(i<n&&j<n)
        {
            if(s.size()&&s.top()==str2[j])
            {//如果栈顶元素与序列2当前的元素相等，则弹栈，序列2集团向后移一位。
                j++;
                s.pop();
                result[k++]=0;
            }
            else
            {//否则从序列1中取当前元素压入栈中。
                if(i==n)break;
                s.push(str1[++i]);
                result[k++]=1;
            }
        }
        if(i==n)//如果I==N表示栈顶元素不等于序列2当前元素，且序列1中元素都已经入过栈，判断不能得到序列2一样的答案。
            cout<<"No."<<endl;
        else
        {//输出进出栈方式
            cout<<"Yes."<<endl;
            for(i=0; i<k; i++)
                if(result[i])
                    cout<<"in"<<endl;
                else
                    cout<<"out"<<endl;
        }
        cout<<"FINISH"<<endl;
    }
    return 0;
}
