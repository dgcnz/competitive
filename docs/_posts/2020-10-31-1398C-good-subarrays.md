---
layout: post
mathjax: true
title: 1398C - Good Subarrays
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
using ll = long long;
using vi = vector<int>;
ll solve(vi a)
{
    int n = (int)a.size();
    ll ans = 0;
    map<ll, int> sum_cnt;
    sum_cnt[0] = 1;
    ll ps = 0;
    for (int i = 0; i < n; ++i)
    {
        ps += a[i];
        ans += sum_cnt[ps];
        ++sum_cnt[ps];
    }
    return ans;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        vi a(n);
        transform(s.begin(), s.end(), a.begin(), [](char c) { return c - '0' - 1; });
        cout << solve(a) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>
