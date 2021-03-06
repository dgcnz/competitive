#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using vi = vector<int>;

string reverse(string s)
{
    reverse(s.begin(), s.end());
    return s;
}

string solve(string s)
{
    string ans;
    vi     alpha(26, 0);

    for (auto c : s)
        alpha[c - 'A'] += 1;

    int oddix = -1;
    for (int i = 0; i < (int)alpha.size(); ++i)
    {
        if (alpha[i] % 2 == 1)
        {
            if (oddix != -1)
                return "NO SOLUTION";
            oddix = i;
        }
        else if (alpha[i] > 0)
        {
            ans.resize(ans.size() + alpha[i] / 2, i + 'A');
        }
    }

    return ans + string(alpha[oddix], oddix + 'A') + reverse(ans);
}

int main(void)
{
    string s;
    cin >> s;

    cout << solve(s) << endl;
    return 0;
}
