#include <iostream>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

using pii=pair<int,int>;

const int maxn = 100005;
#define endl '\n'
int n;
int a[maxn];
map<int,vector<vector<pii> > > mp;
bool vis[maxn];
int cnt[10];
int ans;

template<class T>inline void read(T&x){
    int c;
    for(c=getchar();c<32&&~c;c=getchar());
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
}

int main () {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    read(n);
    for (int i = 1; i <= n; i++){
       read(a[i]);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vector<pii> _;
            _.emplace_back(i,a[i]);
            vis[i]=true;
            int t=a[i];
            while(t!=i){
                vis[t]=true;
                _.emplace_back(t,a[t]);
                t=a[t];
            }
            int sz=_.size();
            mp[sz].push_back(_);
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->first==2){
            cnt[2]+=it->second.size();
        }else if(it->first==3){
            cnt[3]+=it->second.size();
        }else if(it->first==4||it->first==5){
            cnt[5]+=it->second.size();
        }else if(it->first>5){
            int t=it->first/4;
            int tt=it->first-t*4;
            cnt[5]+=it->second.size()*t;
            cnt[tt]+=it->second.size();
        }
    }
    // cout<<111<<endl;
    ans+=cnt[5];
    if(cnt[3]>=cnt[2]){
        ans+=cnt[2];
        int t=cnt[3]-cnt[2];
        int tt=t/3;
        tt*=2;
        //cout<<t<<' '<<tt<<endl;
        ans+=tt;
        ans+=t%3;
    }else{
        ans+=cnt[3];
        int t=cnt[2]-cnt[3];
        int tt=t/2;
        ans+=tt;
        ans+=t-tt*2;
    }
    printf("%d\n",ans);
    //cout<<ans<<endl;
    auto it=mp.end();
    it--;

    while(true){
//        if(n==100000&&a[1]==62168)
//            cout<<it->first<<endl;
        if(it->first==3||it->first==2)
            break;

        if(it->first>=6){
            for(auto &x:it->second){
                while(x.size()>5){
                    printf("5\n");
                   // cout<<5<<endl;
                    for(int i=0;i<5;i++){
                       // cout<<x[i].first<<' ';
                        printf("%d ",x[i].first);
                    }
                    cout<<endl;
                    for(int i=0;i<4;i++){
                        printf("%d ",x[i].second);
                        //cout<<x[i].second<<' ';
                    }
                    printf("%d\n",x[0].first);
                   // cout<<x[0].first<<endl;
                    x[4].first=x[0].first;
                    x.erase(x.begin(),x.begin()+4);
                }
                if(x.size()<=5){
                    mp[x.size()].emplace_back(x);
                }
            }
        }else if(it->first==4||it->first==5){
            for(auto &x:it->second){
                printf("%d\n",it->first);
                //cout<<it->first<<endl;
                for (auto &i : x)
                    printf("%d ",i.first);
                    //cout<< i.first<<' ';
                //cout<<endl;
                printf("\n");
                for (auto &i : x) {
                    printf("%d ",i.second);
                    //cout<< i.second<<' ';
                }
                printf("\n");
               // cout<<endl;
            }
        }
        if(it==mp.begin())
            break;
        it--;
    }
   // cout<<mp[3].size()<<' '<<mp[2].size()<<endl;
    if(mp[3].size()>=mp[2].size()){
        int sz=mp[2].size();
        for(int i=0;i<sz;i++){
            printf("5\n");
//            cout<<5<<endl;
            for(int j=0;j<3;j++)
                printf("%d ",mp[3][i][j].first);
//                cout<<mp[3][i][j].first<<' ';
            for(int j=0;j<2;j++)
                printf("%d ",mp[2][i][j].first);
//                cout<<mp[2][i][j].first<<' ';
//            cout<<endl;
            printf("\n");
            for(int j=0;j<3;j++)
                printf("%d ",mp[3][i][j].second);
               // cout<<mp[3][i][j].second<<' ';
            for(int j=0;j<2;j++)
                printf("%d ",mp[2][i][j].second);
               // cout<<mp[2][i][j].second<<' ';
            //cout<<endl;
            printf("\n");
        }
        mp[3].erase(mp[3].begin(),mp[3].begin()+sz);
       // cout<<"sz= "<<mp[3].size()<<endl;
        while(mp[3].size()>=3){
            printf("5\n");
           // cout<<5<<endl;
            for(int i=0;i<3;i++)
                printf("%d ",mp[3][0][i].first);
//                cout<<mp[3][0][i].first<<' ';
            printf("%d %d\n",mp[3][1][0].first,mp[3][1][1].first);
//            cout<<mp[3][1][0].first<<' '<<mp[3][1][1].first<<endl;
            for(int i=0;i<3;i++)
                printf("%d ",mp[3][0][i].second);
                //cout<<mp[3][0][i].second<<' ';
            printf("%d %d\n",mp[3][1][0].second,mp[3][1][0].first);
            //cout<<mp[3][1][0].second<<' '<<mp[3][1][0].first<<endl;
            mp[3][1][1].first=mp[3][1][0].first;
            printf("5\n");
            //cout<<5<<endl;
            printf("%d %d ",mp[3][1][1].first,mp[3][1][2].first);
           // cout<<mp[3][1][1].first<<' '<<mp[3][1][2].first<<' ';
            for(int i=0;i<3;i++)
                printf("%d ",mp[3][2][i].first);
               // cout<<mp[3][2][i].first<<' ';
            //cout<<endl;
            printf("\n");
            printf("%d %d ",mp[3][1][1].second,mp[3][1][2].second);
//            cout<<mp[3][1][1].second<<' '<<mp[3][1][2].second<<' ';
            for(int i=0;i<3;i++)
                printf("%d ",mp[3][2][i].second);
//                cout<<mp[3][2][i].second<<' ';
//            cout<<endl;
            printf("\n");
            mp[3].erase(mp[3].begin(),mp[3].begin()+3);
         //   cout<<"sz= "<<mp[3].size()<<endl;
        }
        for(int i=0;i<mp[3].size();i++){
            printf("3\n");
           // cout<<3<<endl;
            for(int j=0;j<3;j++)
                printf("%d ",mp[3][i][j].first);
//                cout<<mp[3][i][j].first<<' ';
//            cout<<endl;
            printf("\n");
            for(int j=0;j<3;j++)
                printf("%d ",mp[3][i][j].second);
               // cout<<mp[3][i][j].second<<' ';
            //cout<<endl;
            printf("\n");
        }
       // cout<<111<<endl;
    }else{
        int sz=mp[3].size();
        for(int i=0;i<sz;i++){
            printf("5\n");
           // cout<<5<<endl;
            for(int j=0;j<3;j++)
                printf("%d ",mp[3][i][j].first);
               // cout<<mp[3][i][j].first<<' ';
            for(int j=0;j<2;j++)
                printf("%d ",mp[2][i][j].first);
               // cout<<mp[2][i][j].first<<' ';
            //cout<<endl;
            printf("\n");
            for(int j=0;j<3;j++)
                printf("%d ",mp[3][i][j].second);
//                cout<<mp[3][i][j].second<<' ';
            for(int j=0;j<2;j++)
                printf("%d ",mp[2][i][j].second);
//                cout<<mp[2][i][j].second<<' ';
//            cout<<endl;
            printf("\n");
        }
        mp[2].erase(mp[2].begin(),mp[2].begin()+sz);
        if(mp[2].size()%2==0){
            int sz1=mp[2].size();
            for(int i=0;i<sz1;i+=2){
                cout<<4<<endl;
                cout<<mp[2][i][0].first<<' '<<mp[2][i][1].first<<' '<<mp[2][i+1][0].first<<' '<<mp[2][i+1][1].first<<endl;
                cout<<mp[2][i][0].second<<' '<<mp[2][i][1].second<<' '<<mp[2][i+1][0].second<<' '<<mp[2][i+1][1].second<<endl;
            }
        }else{
            int sz1=mp[2].size();
            for(int i=0;i<sz1-1;i+=2){
                cout<<4<<endl;
                cout<<mp[2][i][0].first<<' '<<mp[2][i][1].first<<' '<<mp[2][i+1][0].first<<' '<<mp[2][i+1][1].first<<endl;
                cout<<mp[2][i][0].second<<' '<<mp[2][i][1].second<<' '<<mp[2][i+1][0].second<<' '<<mp[2][i+1][1].second<<endl;
            }
            cout<<2<<endl;
            cout<<mp[2][sz1-1][0].first<<' '<<mp[2][sz1-1][1].first<<endl;
            cout<<mp[2][sz1-1][0].second<<' '<<mp[2][sz1-1][1].second<<endl;
        }
    }
    return 0;
}
