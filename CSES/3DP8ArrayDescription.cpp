#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];

// Typedefs
typedef long long ll;
typedef vector<int> vec;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Function to check if a number is valid
bool valid(int a, int b) {
    return a >= 1 && a <= b;
}

// Solve
void solve() {
    int n, m; 
    cin >> n >> m;
    vec a(n);
    read(a, n);

    // DP table
    vector<vec> dp(n + 1, vec(m + 1, 0));

    // Initialize first row based on a[0]
    for (int j = 1; j <= m; j++) {
        if (a[0] == j || a[0] == 0) {
            dp[1][j] = 1;
        }
    }

    // Fill DP table
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // Check if current a[i-1] matches j
            if (a[i - 1] != 0 && a[i - 1] != j) {
                dp[i][j] = 0;
                continue;
            }
            // Check valid k's in the previous row
            for (int k = j - 1; k <= j + 1; k++) {
                if (valid(k, m)) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                }
            }
        }
    }   

    // Calculate the answer
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans << endl;
}

int main() {
    fast();
    solve();
    return 0;
}
