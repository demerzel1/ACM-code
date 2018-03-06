#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
string word;
map<string,int> M;
int Dabiao(){
    int cnt=1;
    for(char a='a';a<='z';a++){
        string w;
        w=a;
        M[w]=cnt;
        cnt++;
    }
    for(char a='a';a<='z';a++)
        for(char b=a+1;b<='z';b++){
            string w;
            w=a;
            w+=b;
            M[w]=cnt;
            cnt++;
    }
    for(char a='a';a<='z';a++)
        for(char b=a+1;b<='z';b++)
            for(char c=b+1;c<='z';c++){
                string w;
                w=a;
                w+=b;
                w+=c;
                M[w]=cnt;
                cnt++;
        }
    for(char a='a';a<='z';a++)
        for(char b=a+1;b<='z';b++)
            for(char c=b+1;c<='z';c++)
                for(char d=c+1;d<='z';d++){
                    string w;
                    w=a;
                    w+=b;
                    w+=c;
                    w+=d;
                    M[w]=cnt;
                    cnt++;
            }
    for(char a='a';a<='z';a++)
        for(char b=a+1;b<='z';b++)
            for(char c=b+1;c<='z';c++)
                for(char d=c+1;d<='z';d++)
                    for(char e=d+1;e<='z';e++){
                        string w;
                         w=a;
                        w+=b;
                        w+=c;
                        w+=d;
                        w+=e;
                        M[w]=cnt;
                        cnt++;
                }
}

int main(){
    Dabiao();
    while(cin>>word){
        printf("%d\n",M[word]);
    }
    return 0;
}
