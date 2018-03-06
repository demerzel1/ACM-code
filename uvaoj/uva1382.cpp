#include<bits/stdc++.h>
using namespace std;
#define maxn 105
typedef struct point{
    int x;
    int y;
    point(int xx=0,int yy=0){
        x=xx;
        y=yy;
    }
}point;

vector<point> p;
vector<int> y;
int on[maxn];
int on2[maxn];
int le[maxn];

bool cmp(point a,point b){
    return a.x<b.x;
}

int main(){
    int n;
    int cas=0;
    while(cin>>n&&n){
        p.clear();
        y.clear();
        memset(on,0,sizeof(on));
        memset(on2,0,sizeof(on2));
        memset(le,0,sizeof(le));
        cas++;
        int a,b;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            p.push_back(point(a,b));
            y.push_back(b);
        }
        if(n<=3){
            cout<<"Case "<<cas<<": "<<n<<"\n";
            continue;
        }
        sort(y.begin(),y.end());
        sort(p.begin(),p.end(),cmp);
//        for(int i=0;i<p.size();i++){
//            cout<<p[i].x<<" "<<p[i].y<<"\n";
//        }
//        for(int i=0;i<y.size();i++)
//            cout<<y[i]<<"\n";
        y.erase(unique(y.begin(),y.end()),y.end());
        int sz=y.size();
        int ans=0;
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                int ind=0;
                for(int k=0;k<p.size();k++){
                    if(k==0||p[k].x!=p[k-1].x){
                        ind++;
                        on[ind]=on2[ind]=0;
                        le[ind]=le[ind-1]+on2[ind-1]-on[ind-1];
                    }
                    if(y[i]<=p[k].y&&p[k].y<=y[j])
                        on2[ind]++;
                    if(y[i]<p[k].y&&p[k].y<y[j])
                        on[ind]++;
                }
                if(ind<=2){
                    ans=n;
                    goto tiao;
                }
                int t=0;
                for(int k=1;k<=ind;k++){
                    ans=max(ans,le[k]+on2[k]+t);
                    t=max(t,on[k]-le[k]);
                }
            }
        }
tiao:       cout<<"Case "<<cas<<": "<<ans<<"\n";
    }
    return 0;
}
