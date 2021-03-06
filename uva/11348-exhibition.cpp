#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()

using namespace std;
int const AMAX = 1e4 + 11;

int main(void)
{
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc)
    {
        int n;
        cin >> n;

        vector<set<int>> stamps(n);
        vector<int>      cnt(AMAX, 0), ans(n, 0);

        for (int i = 0; i < n; ++i)
        {
            int m, x;
            cin >> m;
            while (m--)
            {
                cin >> x;
                stamps[i].insert(x);
            }
            for (auto x : stamps[i])
                cnt[x]++;
        }
        for (int i = 0; i < n; ++i)
            for (auto x : stamps[i])
                ans[i] += (cnt[x] == 1);

        int total = accumulate(all(ans), 0);
        cout << "Case " << tc << ": ";
        for (int i = 0; i < n; ++i)
            cout << fixed << setprecision(6) << (ans[i] * 100.0) / (double)total
                 << "%" << (i < n - 1 ? " " : "");
        cout << endl;
    }
    return 0;
}
