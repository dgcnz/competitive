// STATUS: ACCEPTED

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define NMAX 300100

using namespace std;
using ll = long long;

struct Song {
  ll length;
  ll beauty;

  bool operator<(const Song &s) const { return (beauty < s.beauty); }
};

int n, k;
Song songs[NMAX];

ll max_pleasure(void) {
  ll ans = 0, cur = 0, len = 0;
  priority_queue<ll, vector<ll>, greater<ll>> pq;

  sort(songs, songs + n);

  for (int i = n - 1; i >= 0; --i) {
    len += songs[i].length;

    if (pq.size() == k) {
      len -= pq.top();
      pq.pop();
    }

    pq.push(songs[i].length);
    cur = len * songs[i].beauty;

    ans = max(ans, cur);
  }

  return ans;
}

int main(void) {

  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> songs[i].length;
    cin >> songs[i].beauty;
  }

  cout << max_pleasure() << endl;

  return 0;
}
