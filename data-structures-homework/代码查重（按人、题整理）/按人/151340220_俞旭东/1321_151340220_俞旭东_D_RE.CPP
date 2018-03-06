#include <iostream>
#include<queue>
#include<cmath>
#include<memory.h>
#include<cstdio>

using namespace std;
class Kakapo{
private:
    priority_queue<int>k;
    priority_queue<int>a;
    int sum,n,m;
public:
    Kakapo(int a=0,int b=0){n=a;m=b;}
    void init();
    void readcase();
    int computing();
};
void Kakapo::init(){
while(!k.empty())
    k.pop();
while(!a.empty())
    a.pop();
    sum=0;
}
void Kakapo::readcase(){
    for(int i=0;i<m;i++)
    {
        int temp;
        cin>>temp;
        k.push(temp);
    }
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        a.push(temp);
    }
}
int Kakapo::computing(){
    while(!a.empty())
    {
        int p=a.top();
        int q;
        while(p<k.top()&&!k.empty())
        {
            q=k.top();
            k.pop();
        }
        if(abs(p-q)>abs(p-k.top()))
        {
            sum+=abs(p-k.top());
            k.pop();
        }
        else
            sum+=abs(p-q);
        a.pop();
    }
    return sum;


}
int main()
{
    int a,b;
    while(cin>>a>>b){
        Kakapo kk(a,b);
        kk.init();
        kk.readcase();
        cout<<kk.computing()<<endl;

    }
    return 0;
}

