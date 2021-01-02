---
layout: post
mathjax: true
title: 101755L - Queries On A String
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
int main(void)
{
    int q, n;
    char c;
    string s, qtype;
    set<pair<char, int>> sorted_string;
    cin >> s;
    cin >> q;
    n = s.size();
    for (int i = 0; i < n; ++i)
        sorted_string.emplace(s[i], i);
    vector<pair<int, bool>> ans;
    ans.emplace_back(-1, true);
    while (q--)
    {
        cin >> qtype;
        if (qtype[1] == 'u')
        {
            cin >> c;
            auto it = sorted_string.upper_bound({c, ans.back().first});
            if (it != sorted_string.end() and c == it->first)
                ans.emplace_back(it->second, ans.back().second);
            else
                ans.emplace_back(ans.back().first, false);
        }
        else
            ans.pop_back();
        cout << (ans.back().second ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```
</details>
