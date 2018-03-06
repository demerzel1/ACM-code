#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v;
int N, M, a[10];
bool flag[10];

void foo(int k, int m)
{
    if (k == N)
        return;

    foo(k + 1, m);
    flag[k] = true;
    m *= a[k];
    foo(k + 1, m);
    v.push_back(m);
}

int main()
{
    std::ios::sync_with_stdio(false);

    while (std::cin >> N >> M)
    {
        v.clear();
        v.push_back(M);
        std::fill(flag, flag + 10, false);

        for (int i = 0; i < N; ++i)
            std::cin >> a[i];

        foo(0, M);
        std::cout << *std::max_element(v.begin(), v.end()) << std::endl;
    }

    return 0;
}

