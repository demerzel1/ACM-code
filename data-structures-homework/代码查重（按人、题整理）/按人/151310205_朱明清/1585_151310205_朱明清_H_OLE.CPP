#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

#define Max 1000010

using namespace std;
 string str1;
string str2;
 int length;
  int l;
  int Next[Max];
  int num[Max];
  int flag(0);

  void setNext(){
  int i(0), j(-1);
  while(i < l){
    if(j == -1 || str2[i] == str2[j]) Next[++i] = ++j;
    else j = Next[j];
  }
  }

  void Find(){
  int i(0), j(0);
  while(i < length){
    if(j == -1 || str1[i] == str2[j]) {
        ++i, ++j;
    }
    else j = Next[j];

    if(j == l)
    {
        num[flag] = i - j + 1;
        flag++;
    }

  }
 // cout << -1;
  }

int main()
{

    while(scanf("%d", &length) != EOF)
    {
        memset(Next, -1, sizeof(Next));
        memset(num, 0, sizeof(num));
        flag = 0;
        getchar();
       getline(cin, str1);
        cin >> l;
       getchar();
        getline(cin, str2);
        setNext();
        Find();
        printf("%d\n", flag);
        for(int i(0); i<flag; i++){
            if(i) printf(" ");
            printf("%d", num[i]);
        }
        printf("\n");
    }


    return 0;
}



