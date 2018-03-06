
#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
struct point{
    int x,y;
    };
    bool operator <(const point a,const point b){
        if(a.x==b.x)return a.y<b.y;
        else return a.x<b.x;
    }


int main()
{
    int m,n;
    while(cin>>m>>n){
            int c;
            cin>>c;
            set<point>p;
            while(c--)
            {
                point temp;
                cin>>temp.x>>temp.y;
                set<point>::iterator it=p.find(temp);
                if(it!=p.end())
                        cout<<"NO"<<endl;
                        else{p.insert(temp);
                        cout<<"YES"<<endl;
                    }


            }

    }

    return 0;
}

