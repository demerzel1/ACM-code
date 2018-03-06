#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int type;
    int ind;
    Node(char c,int i){
        if(c=='B')
            type=1;
        else if(c=='S')
            type=0;
        ind=i;
    }
}node;

vector<node> v;


int main(){
    int T;
    cin>>T;
    int cas=0;
    while(T--){
        cas++;
        v.clear();
        int n,l;
        cin>>n>>l;
        v.push_back(node('B',0));
        for(int i=0;i<n;i++){
            char c1,c2;
            int x;
            cin>>c1>>c2>>x;
            getchar();
            v.push_back(node(c1,x));
        }
        v.push_back(node('B',l));
        int pre1=0,pre2=0,now1=0,now2=0;
        bool flag=true;
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i].type==1){
                now1=v[i].ind;
                now2=v[i].ind;
                ans=max(ans,max(now1-pre1,now2-pre2));
                pre1=now1;
                pre2=now2;
            }else{
                if(flag){
                    now1=v[i].ind;
                    ans=max(ans,now1-pre1);
                    pre1=now1;
                }else{
                    now2=v[i].ind;
                    ans=max(ans,now2-pre2);
                    pre2=now2;
                }
                flag=!flag;
            }
        }
        cout<<"Case "<<cas<<": "<<ans<<"\n";
    }
    return 0;
}
