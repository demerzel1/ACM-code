#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define maxn 5005

int n;
string op;
int numop;
int ind=0;
int atop=-1;

map<int,int> mp;
map<int,int> mpind;

typedef struct node {
    int u;
    ll w;
    node(int uu=0) {
        u=uu;
        w=0;
    }
} node;

node gf[maxn];

void add(int u) {
    if(mp[u]==1) {
        cout<<"same priority";
    } else {
        mp[u]=1;
        gf[ind]=node(u);
        mpind[u]=ind;
        ind++;
        cout<<"success";
    }
    return;
}

void close(int u) {
    if(mp[u]==0) {
        cout<<"invalid priority";
    } else {
        int tind=mpind[u];
        mp[u]=0;
        mpind[u]=-1;
        if(atop==u)
            atop=-1;
        cout<<"close "<<u<<" with "<<gf[tind].w;
        for(int i=tind+1; i<ind; i++) {
            gf[i-1]=gf[i];
            mpind[gf[i].u]=i-1;
        }
        ind--;
        gf[ind]=node(0);
    }
    return;
}

void chat(int w) {
    if(ind==0) {
        cout<<"empty";
    } else {
        cout<<"success";
        if(atop!=-1) {
            gf[mpind[atop]].w+=(ll)w;
        } else {
            gf[0].w+=(ll)w;
        }
    }
    return;
}

void retate(int x) {
    x--;
    if(x<0||x>=ind) {
        cout<<"out of range";
    } else {
        cout<<"success";
        node t=gf[x];
        mpind[gf[x].u]=0;
        for(int i=x; i>0; i--) {
            gf[i]=gf[i-1];
            mpind[gf[i-1].u]=i;
        }
        gf[0]=t;
    }
    return;
}

void prior() {
    if(ind==0) {
        cout<<"empty";
        return;
    }
    cout<<"success";
    int maxu=-1;
    int x=-1;
    for(int i=0; i<ind; i++) {
        if(maxu<gf[i].u) {
            maxu=gf[i].u;
            x=i;
        }
    }
    node t=gf[x];
    mpind[gf[x].u]=0;
    for(int i=x; i>0; i--) {
        gf[i]=gf[i-1];
        mpind[gf[i-1].u]=i;
    }
    gf[0]=t;
    return;
}

void choose(int u){
    if(mp[u]==0){
        cout<<"invalid priority";
        return;
    }
    cout<<"success";
    int x=mpind[u];
    node t=gf[x];
    mpind[gf[x].u]=0;
    for(int i=x; i>0; i--) {
        gf[i]=gf[i-1];
        mpind[gf[i-1].u]=i;
    }
    gf[0]=t;
    return;
}

void Top(int u){
    if(mp[u]==0){
        cout<<"invalid priority";
        return;
    }
    cout<<"success";
    atop=u;
    return;
}

void untop(){
    if(atop==-1)
        cout<<"no such person";
    else{
        cout<<"success";
        atop=-1;
    }
    return;
}


int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        mp.clear();
        mpind.clear();
        atop=-1;
        ind=0;
        memset(gf,0,sizeof(gf));
        cin>>n;
        for(int i=1;i<=n;i++){
            cout<<"Operation #"<<i<<": ";
            cin>>op;
            if(op=="Add"){
                cin>>numop;
                add(numop);
            }
            if(op=="Prior"){
                prior();
            }
            if(op=="Chat"){
                cin>>numop;
                chat(numop);
            }
            if(op=="Top"){
                cin>>numop;
                Top(numop);
            }
            if(op=="Close"){
                cin>>numop;
                close(numop);
            }
            if(op=="Rotate"){
                cin>>numop;
                retate(numop);
            }
            if(op=="Choose"){
                cin>>numop;
                choose(numop);
            }
            if(op=="Untop"){
                untop();
            }
            cout<<".\n";
        }
        if(ind>0){
            if(atop!=-1&&gf[mpind[atop]].w>0){
                cout<<"Bye "<<gf[mpind[atop]].u<<": "<<gf[mpind[atop]].w<<"\n";
                for(int i=mpind[atop];i<ind-1;i++){
                    gf[i]=gf[i+1];
                }
                ind--;
            }
            for(int i=0;i<ind;i++){
                if(gf[i].w==0)
                    continue;
                cout<<"Bye "<<gf[i].u<<": "<<gf[i].w<<"\n";
            }
        }
    }
    return 0;
}
