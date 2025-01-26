// https://codeforces.com/contest/2023/problem/B

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define up(v) upper_bound(v)
#define low(v) lower_bound(v)

// #define rep(i, x, n)   for(int i = x; i < n; ++i)
// #define rrep(i, x, n)  for(int i = x; i >= n; --i)

// Read and Print
#define read(a, n)                                                             \
  for (ll i = 0; i < n; ++i)                                                   \
    cin >> a[i];
#define print(a, n)                                                            \
  for (ll i = 0; i < n; ++i) {                                                 \
    cout << a[i] << " ";                                                       \
  }                                                                            \
  cout << "\n";
#define endl "\n"
#define sp " "

// Typedefs
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll> pll;
typedef pair<lli, lli> plli;
typedef pair<int, int> pii;
typedef vector<lli> vi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
  ll n, ans = 0;
  cin >> n;
  vi a(n), b(n);
  vi pre(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pre[i + 1] = pre[i] + a[i];
  }
  read(b, n);
  vi dis(n + 1, 1e17);
  priority_queue<pll> pq;
  pq.push({0, 1});
  dis[0] = 0;
  while (pq.size()) {
    auto it = pq.top();
    pq.pop();
    ll d = -1ll * (it.first), x = it.second;
    if (dis[x] < d)
      continue;
    dis[x] = d;
    if (b[x - 1] > x) {
      if (dis[b[x - 1]] > d + a[x - 1]) {
        dis[b[x - 1]] = d + a[x - 1];
        pq.push({-1ll * (d + a[x - 1]), b[x - 1]});
      }
    }
    if (x != 1 && dis[x - 1] > d) {
      dis[x - 1] = d;
      pq.push({-1ll * (d), x - 1});
    }
  }
  for (int i = 1; i <= n; i++) {
    ll x = pre[i] - dis[i];
    ans = max(ans, x);
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
