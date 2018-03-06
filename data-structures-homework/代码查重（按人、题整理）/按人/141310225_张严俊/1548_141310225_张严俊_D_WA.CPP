#include <iostream>
#include <algorithm>
#include <cmath>

int closestNum(int n, int num[], size_t length)
{
    size_t low = 0, high = length - 1;

    while (low <= high)
    {
        size_t mid = (low + high) >> 1;
        int a, b;

        if (mid >= 1 && n >= num[mid - 1] && n <= num[mid])
        {
            a = n - num[mid - 1];
            b = num[mid] - n;
            return (a < b) ? num[mid - 1] : num[mid];
        }
        else if (mid + 1 < length && n >= num[mid] && n <= num[mid + 1])
        {
            a = n - num[mid];
            b = num[mid + 1] - n;
            return (a < b) ? num[mid] : num[mid + 1];
        }
        else if (mid >= 1 && n < num[mid - 1])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
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
                sum += std::abs(closestNum(k[i], a, m) - k[i]);
        }
        else
        {
            for (int i = 0; i < m; ++i)
                sum += std::abs(a[i] - closestNum(a[i], k , n));
        }

        std::cout << sum << std::endl;
    }

    return 0;
}

