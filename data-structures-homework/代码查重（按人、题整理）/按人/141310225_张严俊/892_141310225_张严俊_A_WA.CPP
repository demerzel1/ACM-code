#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v;
int N, M, a[10];
bool flag[10];

void foo(int k)
{
    if (k == N)
        return;

    if (flag[k])
    {
        M *= a[k];
        foo(k + 1);
    }
    else
    {
        flag[k] = true;
        foo(k);
    }

    v.push_back(M);
}

int main()
{
    std::ios::sync_with_stdio(false);

    while (std::cin >> N >> M)
    {
        v.clear();
        std::fill(flag, flag + 10, false);

        for (int i = 0; i < N; ++i)
            std::cin >> a[i];

        foo(0);
        std::cout << *std::max_element(v.begin(), v.end()) << std::endl;
    }

    return 0;
}

