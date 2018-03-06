#include<bits/stdc++.h>
using namespace std;

/*
h---1
d---2
s---3
c---4
*/
typedef struct node{
    int val;
    int flo;
}node;

bool cmp(node a,node b){
    return a.val<b.val;
}

node card[2][6];
int level[2];

int change1(char c){
    if(c>='0'&&c<='9')
        return c-'0';
    if(c=='A')
        return 1;
    if(c=='J')
        return 11;
    if(c=='Q')
        return 12;
    if(c=='K')
        return 13;
}

int change2(char c){
    if(c=='H')
        return 1;
    if(c=='D')
        return 2;
    if(c=='S')
        return 3;
    if(c=='C')
        return 4;
}
/*
straight flush 1
four of a kind 2
full house 3
flush 4
straight 5
three of a kind 6
two pairs 7
pair 8
high card 9
*/
pair<int,int> judge1(int x){
    int l=1;
    bool flag_flo=true;
    for(int i=1;i<5;i++){
        if(card[x][i].flo!=card.flo[x][i-1]){
            flag_flo=false;
            break;
        }
    }
    bool flag_flush=true;
    for(int i=1;i<5;i++){
        if(card[x][i].val-card[x][i-1].val!=1){
            flag_flush=false;
            break;
        }
    }
    if(flag_flo&&flag_flush)
        return make_pair(l,);
    l--;
    if((card[x][0].val==card[x][1].val&&card[x][0].val==card[x][2].val&&card[x][0].val==card[x][3].val)||
    (card[x][1].val==card[x][2].val&&card[x][1].val==card[x][3].val&&card[x][1].val==card[x][4].val)){
        return l;
    }
    l--;
}

int main(){
    string s;
    while(cin>>s){
        memset(level,0,sizeof(level));
        //input
        if(s[1]=='0'){
            card[0][0].val=10;
            card[0][0].flo=change2(s[2]);
        }
        for(int i=1;i<5;i++){
            cin>>s;
            if(s[1]=='0'){
                card[0][i].val=10;
                card[0][i].flo=change2(s[2]);
            }else{
                card[0][i].val=change1(s[0]);
                card[0][i].flo=change2(s[1]);
            }
        }
        for(int i=0;i<5;i++){
            cin>>s;
            if(s[1]=='0'){
                card[1][i].val=10;
                card[1][i].flo=change2(s[2]);
            }else{
                card[1][i].val=change1(s[0]);
                card[1][i].flo=change2(s[1]);
            }
        }
        //input end
        sort(card[0],card[0]+5,cmp);
        sort(card[1],card[1]+5,cmp);
    }
}
