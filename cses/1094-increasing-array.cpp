#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

const int NMAX = 2e5 + 11;

int a[NMAX];

int main(void)
{
    int n;
    ll  ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 1; i < n; ++i)
    {
        ans += max(0, a[i - 1] - a[i]);
        a[i] = max(a[i - 1], a[i]);
    }

    cout << ans << endl;

    return 0;
}
