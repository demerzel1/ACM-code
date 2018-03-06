#include<bits/stdc++.h>
using namespace std;
#define maxn 100005

typedef struct Line{
    int l;
    int r;
    Line(int ll=0,int rr=0){
        l=ll;
        r=rr;
    }
}line;

bool cmp(line a,line b){
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}

vector<line> l;

int M;
bool vis[maxn];

int main(){
    int T;
    cin>>T;
    while(T--){
        l.clear();
        memset(vis,false,sizeof(vis));
        cin>>M;
        bool flag=false;
        while(true){
            int a,b;
            cin>>a>>b;
            if(a==0&&b==0)
                break;
            if(b<0||a>M)
                continue;
            l.push_back(line(a,b));
        }
        sort(l.begin(),l.end(),cmp);
        int ts=0;
        int pre=-1;
        int tr=0;
        for(int i=0;i<l.size();i++){
            if(l[i].l<=ts){
                if(tr<l[i].r){
                    vis[i]=true;
                    if(pre>=0)
                        vis[pre]=false;
                    pre=i;
                    tr=max(tr,l[i].r);
                }
            }else{
                if(ts==tr){
                    flag=false;
                    break;
                }
                ts=tr;
                i--;
                pre=-1;
            }
            if(tr>=M){
                flag=true;
                break;
            }
        }
        if(tr>=M)
            flag=true;
        if(flag){
            int ans=0;
            for(int i=0;i<l.size();i++)
                if(vis[i])
                    ans++;
            cout<<ans<<"\n";
            for(int i=0;i<l.size();i++)
                if(vis[i])
                    cout<<l[i].l<<" "<<l[i].r<<"\n";
        }else
            cout<<"0\n";
        cout<<"\n";
    }
    return 0;
}
