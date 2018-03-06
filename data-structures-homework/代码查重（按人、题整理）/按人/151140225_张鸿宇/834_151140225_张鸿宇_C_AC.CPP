#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, bool> board;
int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    while(cin >> n >> m)
    {
        int q;
        cin >> q;
        for(int i = 0; i < q; ++i)
        {
            int a, b; cin >> a >> b;
            pair<int, int> temp(a, b);
            if(board.find(temp) == board.end())
            {
                cout << "YES" << endl;
                board[temp] = true;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        board.clear();
    }
    return 0;
}


