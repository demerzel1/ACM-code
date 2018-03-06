#include <iostream>
#include <queue>
#include <vector>

int main()
{
    int n;
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

    std::ios::sync_with_stdio(false);

    while (std::cin >> n)
    {
        int cost = 0;
        pq = std::priority_queue<int, std::vector<int>, std::greater<int> >();

        for (int i = 0; i < n; ++i)
        {
            int m;
            std::cin >> m;
            pq.push(m);
        }

        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            b += a;
            cost += b;
            pq.push(b);
        }

        std::cout << cost << std::endl;
    }

    return 0;
}

