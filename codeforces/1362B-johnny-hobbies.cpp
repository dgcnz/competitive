#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1024 + 11;

int n, s[NMAX];

int solve(void)
{
    sort(s, s + n);
    for (int k = 1; k < NMAX; ++k) // iterate all xors
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (binary_search(s, s + n, s[i] ^ k))
                ++cnt;
        if (cnt == n)
            return k;
    }
    return -1;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        cout << solve() << endl;
    }

    return 0;
}
