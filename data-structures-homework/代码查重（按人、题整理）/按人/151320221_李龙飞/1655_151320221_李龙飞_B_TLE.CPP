#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct place
{
    int n;
    int emergency;
    friend bool operator < (place a, place b)
    {
        return a.emergency > b.emergency;
    }
};

int main()
{
    int placeNum, busNum, money, dis[1010][1010], i, j, k, init;
    place p[1010];
    while(cin >> placeNum >> busNum >> money)
    {
        memset(dis, 999999, sizeof(dis));
        for(i=0;i<busNum;i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            dis[x-1][y-1] = z;
            dis[y-1][x-1] = z;
        }
        for(i=0;i<placeNum;i++)
        {
            place tmp;
            cin >> tmp.emergency;
            tmp.n = i;
            p[i] = tmp;
        }
        init = p[0].emergency;
        for(k=0;k<placeNum;k++)
        for(i=0;i<placeNum;i++)
        for(j=0;j<placeNum;j++)
        {
            if(dis[i][k]+dis[k][j]<dis[i][j])
                dis[i][j] = dis[i][k] + dis[k][j];
        }
        sort(p, p+placeNum);
        for(i=0;i<placeNum;i++)
        {
            if(dis[0][p[i].n] <= money)
            {
                cout << p[i].emergency << endl;
                break;
            }
        }
        if(i == placeNum)
            cout << init << endl;
    }
    return 0;
}

