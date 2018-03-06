#include<cstdio>
#include<algorithm>
#include<cstring>
#include<list>
#include<iostream>
#include<cstdlib>
#include<map>
#include<vector>
using namespace std;

int main(){
    list<char> mylist;
    char c;
    list<char>::iterator it;
    it=mylist.begin();
    while(scanf("%c",&c)!=EOF){
        if(c=='\n'){
            for(it=mylist.begin();it!=mylist.end();it++)
                printf("%c",*it);
            printf("\n");
            mylist.clear();
        }
        else if(c!='['&&c!=']'){
            mylist.insert(it,c);
        }
        else if(c=='['){
            it=mylist.begin();
        }
        else if(c==']'){
            it=mylist.end();
        }
    }
    return 0;
}
