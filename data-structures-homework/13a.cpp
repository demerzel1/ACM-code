#include<bits/stdc++.h>
using namespace std;
#define maxn 205
#define inf -1

map<string,int> m;
int cnt=1;
int road[maxn][maxn];
int roadnew[maxn][maxn];

void mset(string s){
    if(m.find(s)==m.end()) m[s]=cnt++;
}
string mvaluefind(int val){
    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
        if(it->second==val)
            return it->first;
}
int main(){
    m.clear();
    memset(road,inf,sizeof(road));
    memset(roadnew,inf,sizeof(roadnew));
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            if(i==j)
                road[i][j]=0;
    cout<<111<<endl;
    string s1,s2;
    string start,ends;
    int value;
    int v,e;
    int a;
    cin>>v>>e;
    cout<<v<<" "<<e<<endl;
    for(int i=0;i<e;i++){
        cin>>s1>>s2>>a;
        mset(s1);
        mset(s2);
        if(a>road[m[s1]][m[s2]]){
            road[m[s1]][m[s2]]=a;
            road[m[s2]][m[s1]]=a;
        }
        cout<<m[s1]<<" "<<m[s2]<<" "<<a<<endl;
}
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<road[i][j]<<" ";
        }
        cout<<endl;
    }
    cin>>start>>ends;
    vector<string> vnew;
    vnew.push_back(start);
    cout<<vnew[0]<<endl;
    while(vnew.size()!=v){
            int minv=10000000;
            int miny=0;
            int x=m[vnew[vnew.size()-1]];
        for(int i=0;i<v;i++){
            if(road[x][i]>0&&road[x][i]<minv){
                minv=road[x][i];
                miny=i;
                printf("x=%d i=%d minv=%d miny=%d road[x][i]=%d\n",x,i,minv,miny,road[x][i]);
            }
        }
        roadnew[x][miny]=minv;
        roadnew[miny][x]=minv;
        string sy=mvaluefind(miny);
        vnew.push_back(sy);
         cout<<vnew[vnew.size()-1]<<endl;
    }
//    for(int i=0;i<v;i++){
//        for(int j=0;j<v;j++){
 //           cout<<roadnew[i][j]<<" ";
 //       }
 //       cout<<endl;
  //  }
    int x=m[start];
    int ans=0;
    cout<<111<<endl;
   while(1){
        int i;
        for(i=0;i<v;i++){
    //            cout<<222<<endl;
            if(roadnew[x][i]>0)
                break;
        }
    //    printf("x=%d,i=%d,m[ends]=%d\n",x,i,m[ends]);
        if(m[ends]!=i){
            x=i;
        }
        else{
            ans=roadnew[x][i];
            break;
        }
   }
   cout<<ans<<endl;
   return 0;
}
