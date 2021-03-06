#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
            return false;
    }
    return true;
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, m;
    cin >> t;

    while (t--)
    {
        cin >> n;
        m = 1;

        if (n % 2 == 1 and n != 1)
            m = 0;
        else if (n == 2)
            m = 0;
        else
        {
            int cnt = 0;
            while (n % 2 == 0)
            {
                n /= 2;
                ++cnt;
            }
            if ((n != 1 and cnt > 1) or (cnt == 1 && !is_prime(n)))
                m = 0;
        }
        cout << (m == 0 ? "Ashishgup" : "FastestFinger") << endl;
    }

    return 0;
}
