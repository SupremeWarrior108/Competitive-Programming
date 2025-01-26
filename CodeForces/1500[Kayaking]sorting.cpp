// https://codeforces.com/problemset/problem/863/B

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define up upper_bound
#define low lower_bound

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
typedef vector<ll> vi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e18 + 6;

// Solve
void solve() {
  int n;
  cin >> n;
  n *= 2;
  vec a(n);
  read(a, n);
  sort(all(a));
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      vec x;
      for (int k = 0; k < n; k++)
        if (k != i && k != j)
          x.pb(a[k]);
      int total = 0;
      for (int k = 0; k < n - 2; k += 2)
        total += x[k + 1] - x[k];
      ans = min(ans, total);
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
