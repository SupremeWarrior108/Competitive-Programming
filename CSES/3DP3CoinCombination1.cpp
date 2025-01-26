//  https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i < n; ++i)
#define rrep(i, x, n)  for(int i = x; i >= n; --i)

// Read and Print
#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    read(a, n);
    vector<int> dp(m + 1, 0);
    dp[0] = 1;  // Base case: one way to make sum 0

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++) {
            if(i - a[j] >= 0) {
                dp[i] = (dp[i] + dp[i - a[j]]) % mod;
            }
        }
    }

    cout << dp[m] << endl;
}

int main(){
    fast();
    solve();

    return 0;
}
