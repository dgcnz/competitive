---
layout: post
mathjax: true
title: 1360D - Buying Shovels
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
int solve(int n, int k)
{
    int ans = INT_MAX, d1, d2;
    for (int i = 1, len = (int)sqrt(n); i <= len; ++i)
    {
        if (n % i == 0)
        {
            d1 = i;
            d2 = n / i;
            if (d2 <= k)
                ans = min(ans, d1);
            if (d1 <= k)
                ans = min(ans, d2);
        }
    }
    return ans;
}
int main(void)
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>
