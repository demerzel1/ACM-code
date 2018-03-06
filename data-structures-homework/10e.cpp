#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<stack>
#include<vector>

using namespace std;

struct Card{
    char x,y;
};
bool check(Card a,Card b){
    if(a.x==b.x||a.y==b.y) return 1;
    return 0;
}
int main(){
    char a,b;
    vector<stack<Card> > v;
    while(scanf("%c%c",&a,&b),a!='#'){
        getchar();
        Card card;
        card.x=a;
        card.y=b;
        stack<Card> s;
        s.push(card);
        v.push_back(s);
        if(v.size()==52){
            int i;
            while(1){
                for(i=0;i<v.size();i++){
                    if(i>2&&check(v[i].top(),v[i-3].top())){
                        v[i-3].push(v[i].top());
                        v[i].pop();
                        break;
                    }
                    if(i>0&&check(v[i].top(),v[i-1].top())){
                        v[i-1].push(v[i].top());
                        v[i].pop();
                        break;
                    }
                }
                if(i==v.size()) break;
                if(v[i].size()==0)
                    v.erase(v.begin()+i);
            }
            if(i==1)
                printf("1 pile remaining:");
            else
                printf("%d piles remaining:",i);
            for(int j=0;j<i;j++){
                printf(" %d",v[j].size());
            }
            printf("\n");
            v.clear();
        }
    }
    return 0;
}
