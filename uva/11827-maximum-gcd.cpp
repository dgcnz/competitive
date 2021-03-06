#include <algorithm>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int MMAX = 1e4 + 11;

int n, m, a[MMAX];

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int    pos, ans;
    string line;

    cin >> n;
    cin.ignore();

    while (n--)
    {
        getline(cin, line);
        stringstream ss(line);
        pos = 0;
        while (ss >> a[pos])
            ++pos;

        m   = pos;
        ans = 0;

        for (int i = 0; i < m - 1; ++i)
            for (int j = i + 1; j < m; ++j)
                ans = max(ans, gcd(a[i], a[j]));

        cout << ans << endl;
    }
    return 0;
}
