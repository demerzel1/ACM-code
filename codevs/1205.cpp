#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
string s[100];
int main(){

    int n=0;

    while (cin>>s[n++]);

    n--;

    while (--n) cout<<s[n]<<" ";

    cout<<s[0];

    return 0;

}
