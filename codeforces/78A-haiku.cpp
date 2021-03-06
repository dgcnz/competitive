#include <bits/stdc++.h>

using namespace std;

inline bool is_vowel(char c)
{
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int count(string line)
{
    int          ans = 0;
    string       word;
    stringstream ss(line);

    while (ss >> word)
    {
        for (auto c : word)
        {
            if (is_vowel(c))
                ++ans;
        }
    }

    return ans;
}

int main(void)
{
    int    line_number     = 0, syllabes_count;
    int    expected_syl[3] = {5, 7, 5};
    string line;

    while (line_number < 3)
    {
        getline(cin, line);
        syllabes_count = count(line);
        if (expected_syl[line_number] != syllabes_count)
        {
            cout << "NO" << endl;
            return 0;
        }
        line_number++;
    }

    cout << "YES" << endl;

    return 0;
}
