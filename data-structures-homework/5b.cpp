#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<deque>
#include<iomanip>
#include<fstream>
using namespace std;

class card{
public:
    char color,size;
    card(char a,char b):size(a),color(b){
    }
    int sizeToInt(){
        switch (size){
            case 'A':
                return 1;
            case 'T':
                return 10;
            case 'J':
                return 11;
            case 'Q':
                return 12;
            case 'K':
                return 13;
            default:
                return size-'0';
        }
    }
};
int main(){
    deque<card> pile[13];
    string data[52];
    while(cin>>data[0],data[0][0]!='#'){
        for(int i=1;i<52;i++){
            cin>>data[i];
        }
        for(int i=0;i<52;i++){
            pile[i%13].push_back(card(data[51-i][0],data[51-i][1]));
        }
        int cur=12;
        int count=0;
        class card &temp=pile[cur].back();
        while(!pile[cur].empty()){
            temp=pile[cur].back();
            pile[cur].pop_back();
            cur=temp.sizeToInt()-1;
            count++;
            }
        cout<<setw(2)<<setfill('0')<<count<<","<<temp.size<<temp.color<<endl;
  //      cout<<temp.color<<endl;
    }
    return 0;
}
