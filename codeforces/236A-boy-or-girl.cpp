#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string       s;
    vector<bool> alph(26, false);
    string       msg[2] = {"CHAT WITH HER!", "IGNORE HIM!"};

    cin >> s;
    for (auto c : s)
        alph[c - 'a'] = true;

    bool ans = accumulate(alph.begin(), alph.end(), 0) % 2;
    cout << msg[ans] << endl;

    return 0;
}
