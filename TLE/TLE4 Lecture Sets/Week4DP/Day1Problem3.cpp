// https://codeforces.com/problemset/problem/1133/E

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()

// Typedefs
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vvi;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve
void solve() {
    int t;  
    cin >> t;
    while(t--) {
        ll n;  
        cin >> n;
        vector<pll> a(n);
        for(auto &x : a)   
            cin >> x.ff >> x.ss;
        
        // Initialize DP table
        vvi dp(n + 1, vector<ll>(3, -1)); // Use n + 1 for clarity

        // Recursive function with memoization
        auto f = [&](int i, int j, auto &&f) -> ll {
            if(i == n) return 0; // Base case: no more pillars to process
            if(dp[i][j] != -1) return dp[i][j];

            ll ans = LLONG_MAX; // Start with maximum value
            
            for(int k = 0; k <= 2; k++) {
                // Check the condition for valid height adjustment
                if(i == 0 || a[i].ff + k != a[i - 1].ff + j) {
                    ans = min(ans, k * a[i].ss + f(i + 1, k, f)); // Update minimum cost
                }
            }

            return dp[i][j] = ans; // Save the computed result
        };

        // Start the recursion
        ll result = f(0, 0, f);
        cout << (result == LLONG_MAX ? 0 : result) << endl; // Handle the case where no valid adjustment is found
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    solve();
    return 0;
}
