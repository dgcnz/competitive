---
layout: post
mathjax: true
title: 907 - Winterim Backpacking Trip
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
const int NMAX = 600 + 11;
int n, k, dist[NMAX];
bool simulate(int max_dist)
{
    int dist_left = max_dist, stops = 0;
    for (int i = 0; i < n + 1; ++i)
    {
        if (dist_left >= dist[i])
            dist_left -= dist[i];
        else
        {
            ++stops;
            dist_left = max_dist - dist[i];
        }
        if (stops > k or dist_left < 0)
            return false;
    }
    return true;
}
int binary_search(int l, int r)
{
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (simulate(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int main(void)
{
    int sum;
    while (cin >> n >> k)
    {
        sum = 0;
        for (int i = 0; i < n + 1; ++i)
        {
            cin >> dist[i];
            sum += dist[i];
        }
        cout << binary_search(0, sum) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>
