#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using si = set<int>;

int main(void)
{
    int n;
    vi  x;
    si  sums;

    cin >> n;

    x.resize(n);
    for (auto &xi : x)
        cin >> xi;

    for (auto xi : x)
    {
        si temp;
        for (auto sum : sums)
            temp.insert(sum + xi);
        sums.insert(xi);
        sums.insert(temp.begin(), temp.end());
    }

    cout << sums.size() << endl;
    for (auto sum : sums)
    {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
