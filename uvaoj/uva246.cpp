#include<bits/stdc++.h>
using namespace std;

vector<deque<int> > pile;
set<vector<deque<int> > > status;
bool can[8];
int cnt=0;
int ans=0;

bool check(int x) {
    if(pile[x].size()<3)
        return false;
    int f1=pile[x].front();
    pile[x].pop_front();
    int f2=pile[x].front();
    pile[x].pop_front();
    int l1=pile[x].back();
    pile[x].pop_back();
   // cout<<"lll "<<f1<<" "<<f2<<" "<<l1<<"\n";
    if(f1+f2+l1==10||f1+f2+l1==20||f1+f2+l1==30) {
     //   cout<<111111<<"\n";
      //  printf("%d %d %d\n",f1,f2,l1);
        pile[0].push_back(f1);
        pile[0].push_back(f2);
        pile[0].push_back(l1);
        return true;
    } else {
        pile[x].push_front(f2);
        int l2=pile[x].back();
        pile[x].pop_back();
        if(f1+l2+l1==10||f1+l2+l1==20||f1+l2+l1==30) {
         //   cout<<2222222<<"\n";
         //   printf("%d %d %d\n",f1,l1,l2);
            pile[0].push_back(f1);
            pile[0].push_back(l2);
            pile[0].push_back(l1);
            return true;
        } else {
            pile[x].push_front(f1);
            int l3=pile[x].back();
            pile[x].pop_back();
            if(l3+l2+l1==10||l3+l2+l1==20||l3+l2+l1==30) {
             //   cout<<333333<<"\n";
             //   printf("%d %d %d\n",l1,l2,l3);
                pile[0].push_back(l3);
                pile[0].push_back(l2);
                pile[0].push_back(l1);
                return true;
            } else {
                pile[x].push_back(l3);
                pile[x].push_back(l2);
                pile[x].push_back(l1);
            }
        }
    }
    return false;
}

int main() {
    int a;
    while(cin>>a&&a) {
        ans=0;
        cnt=0;
        memset(can,false,sizeof(can));
        pile.clear();
        status.clear();
        for(int i=0; i<=7; i++) {
            deque<int> q;
            q.clear();
            pile.push_back(q);
        }
        pile[0].push_back(a);
        for(int i=0; i<51; i++) {
            cin>>a;
         //   cout<<a<<"\n";
            pile[0].push_back(a);
        }
      //  cout<<"111\n";
        int flag=0;
        while(true) {
            for(int i=1; i<8; i++) {
        //        cout<<"i="<<i<<"\n";
                if(cnt==7) {
                    flag=1;
                    break;
                }
                if(pile[0].size()==0) {
                    flag=2;
                    break;
                }
                if(can[i])
                    continue;
                ans++;
                int f=pile[0].front();
                pile[0].pop_front();
            //    cout<<"f:"<<f<<"\n";
                pile[i].push_back(f);
                while(check(i));
            //    cout<<"sz "<<pile[i].size()<<"\n";
                if(pile[i].size()==0) {
             //       cout<<"hhhhhh"<<"  "<<i<<"\n";
                    can[i]=true;
                    cnt++;
                }
                if(status.count(pile)) {
                    flag=3;
                    break;
                }
                status.insert(pile);
            }
            if(flag!=0)
                break;
        }
        if(flag==1) {
            cout<<"Win : "<<ans<<"\n";
        } else if(flag==2) {
            cout<<"Loss: "<<ans<<"\n";
        } else if(flag==3) {
            cout<<"Draw: "<<ans<<"\n";
        }
    }
    return 0;
}
