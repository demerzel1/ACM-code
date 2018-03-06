#include <iostream>
#include <algorithm>
#include <cmath>

int minDiff(int n, int num[], size_t length)
{
    size_t low = 0, high = length - 1;
    int a, b;

    while (high - low >= 2)
    {
        size_t mid = (low + high) >> 1;

        if (n >= num[mid - 1] && n <= num[mid])
        {
            a = n - num[mid - 1];
            b = num[mid] - n;
            return std::min(a, b);
        }
        else if (n >= num[mid] && n <= num[mid + 1])
        {
            a = n - num[mid];
            b = num[mid + 1] - n;
            return std::min(a, b);
        }
        else if (n < num[mid - 1])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (high == low)
        return std::abs(n - num[low]);

    // else if (high - low == 1)
    a = std::abs(n - num[low]);
    b = std::abs(n - num[high]);
    return std::min(a, b);
}

int main()
{
    const size_t N = 100005;
    int n, m, a[N], k[N];

    std::ios::sync_with_stdio(false);

    while (std::cin >> n >> m)
    {
        for (int i = 0; i < m; ++i)
            std::cin >> a[i];
        for (int i = 0; i < n; ++i)
            std::cin >> k[i];

        std::sort(a, a + m);
        std::sort(k, k + n);

        int sum = 0;

        if (n < m)
        {
            for (int i = 0; i < n; ++i)
                sum += minDiff(k[i], a, m);
        }
        else
        {
            for (int i = 0; i < m; ++i)
                sum += minDiff(a[i], k , n);
        }

        std::cout << sum << std::endl;
    }

    return 0;
}

