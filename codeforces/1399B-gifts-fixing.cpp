#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

ll solve(int n, const vi &a, const vi &b)
{
    ll  ans = 0;
    int a0  = *min_element(a.begin(), a.end());
    int b0  = *min_element(b.begin(), b.end());

    for (int i = 0; i < n; ++i)
    {
        ans += max(a[i] - a0, b[i] - b0);
    }

    return ans;
}

int main(void)
{
    int t, n;
    vi  a, b;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.resize(n), b.resize(n);

        for (auto &ai : a)
            cin >> ai;
        for (auto &bi : b)
            cin >> bi;

        cout << solve(n, a, b) << endl;
    }

    return 0;
}
