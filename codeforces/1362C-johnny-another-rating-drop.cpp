#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void)
{
    int t;
    ll  n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        ll ans  = 0;
        ll rate = 1;
        for (int i = 0; i < 64; ++i)
        {
            ans += max((ll)0, (ll)((n + 1 + rate - 1) / rate) - 1);
            rate *= 2;
        }
        cout << ans << endl;
    }
    return 0;
}
