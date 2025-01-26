#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// #define rep(i, x, n)   for(int i = x; i < n; ++i)
// #define rrep(i, x, n)  for(int i = x; i >= n; --i)

// Read and Print
#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";
#define endl "\n"
#define sp " "

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    ll n, m;
    cin >> n >> m;
    
    vector<vector<char>> a(n+1, vector<char>(m+1));
    vector<vec> dp(mxn, vec(3, 0));

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    ll ans = 0;

    for (ll k = 2; k <= n + m; k++) {
        for (ll i = 0; i <= n; i++)
            for (ll j = 0; j < 3; j++)
                dp[i][j] = 0;

        ll j = min(k - 1, m), i = k - j;

        while (i <= n && j >= 1 && j <= m) {
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});

            if (j > 1 && j < m && a[i][j] == 'G' && a[i][j - 1] == 'R' && a[i][j + 1] == 'W') {
                dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
            }
            if (i > 1 && i < n && a[i][j] == 'G' && a[i - 1][j] == 'R' && a[i + 1][j] == 'W') {
                dp[i][2] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
            }

            i++; j--;
        }

        ans += max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}