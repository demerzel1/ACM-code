#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

#define Max 100000

using namespace std;

int main()
{
    int n, m;
   while(scanf("%d%d", &n, &m) != EOF){
    map<int, vector<int> > mymap;
    map<int, vector<int> >::iterator it;
    mymap.clear();
    int numberofchess;
    int x, y;
    scanf("%d", &numberofchess);
    for(int i(0); i<numberofchess; i++){
        scanf("%d%d", &x, &y);
        if(mymap[x].size() == 0)
        {
            printf("YES\n");
               mymap[x].push_back(y);

        }
        else{
                int i(0);
            for(; i<int(mymap[x].size()); i++)
        {
            if(mymap[x][i] == y) break;
           // cout << mymap[x][i] << endl;

        }//cout << i << endl;
        if(i == int(mymap[x].size())){
            printf("YES\n");
               mymap[x].push_back(y);
        }
        else printf("NO\n");
        }


    }
   }

    return 0;
}
