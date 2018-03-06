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
                sort(mymap[x].begin(), mymap[x].end());
                int s = upper_bound(mymap[x].begin(), mymap[x].end(), y) - lower_bound(mymap[x].begin(), mymap[x].end(), y);;
            if(!s) {
            printf("YES\n");
               mymap[x].push_back(y);
        }
        else printf("NO\n");


    }
   }
}
   //map<int, int> mymap;

    return 0;
}



