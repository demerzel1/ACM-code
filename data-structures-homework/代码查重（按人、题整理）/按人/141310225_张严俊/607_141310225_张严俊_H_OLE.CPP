#include <iostream>
#include <vector>

void makeNext(const std::string& P, int next[])
{
    int q, k, m = P.length();

    next[0] = 0;

    for (q = 1, k = 0; q < m; ++q)
    {
        while (k > 0 && P[q] != P[k])
            k = next[k - 1];

        if (P[q] == P[k])
            ++k;

        next[q] = k;
    }
}

void kmp(const std::string& T, const std::string& P, int next[], std::vector<int>& v)
{
    int i, q, n = T.length(), m = P.length();

    makeNext(P, next);

    for (i = q = 0; i < n; ++i)
    {
        while (q > 0 && P[q] != T[i])
            q = next[q - 1];

        if (P[q] == T[i])
            ++q;

        if (q == m)
            v.push_back(i - m + 2);
    }
}

int main()
{
    int n, next[1000010];
    std::string hay, needle;
    std::vector<int> v;

    std::ios::sync_with_stdio(false);

    while (std::cin >> n)
    {
        std::cin.get();
        std::getline(std::cin, hay);
        std::cin >> n;
        std::cin.get();
        std::getline(std::cin, needle);
        v.clear();
        kmp(hay, needle, next, v);

        if (!v.empty())
        {
            std::cout << v.size() << std::endl << v[0];
            for (std::vector<int>::iterator it = v.begin() + 1; it != v.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << std::endl;
        }
        else
            std::cout << 0 << std::endl << std::endl;
    }

    return 0;
}

