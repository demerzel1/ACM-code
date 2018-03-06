#include <iostream>
#include <map>

int main()
{
    int N, M, Q, x, y;
    std::map<std::pair<int, int>, bool> m;

    std::ios::sync_with_stdio(false);

    while (std::cin >> N >> M)
    {
        m.clear();
        std::cin >> Q;

        for (int i = 0; i < Q; ++i)
        {
            std::cin >> x >> y;

            if (x < 1 || x > N || y < 1 || y > M)
            {
                std::cout << "NO" << std::endl;
                continue;
            }

            std::pair<int, int> pos = std::make_pair(x, y);

            if (m.find(pos) == m.end())
            {
                std::cout << "YES" << std::endl;
                m[pos] = true;
            }
            else
                std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

