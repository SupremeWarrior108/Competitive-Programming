// https://codeforces.com/problemset/problem/1392/D

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Print
#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";
#define endl "\n"

// Typedefs
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
using vec = vector<int>;

// Solve

void solve() {
    int t;  
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string st;
        cin >> st;
        int ans = n;
        auto g = [&](int index, vector<vector<vec>> &dp, int sl, int l, int f, int s, auto &&g)->int {
            if (index == n - 1) {
                int changes = 1e7; 
                if ((sl != 0 || l != 0) && (f != 0 || s != 0) && (l != 0 || f != 0))
                    changes = min(changes, st[index] != 'L' ? 1 : 0);
                if ((sl != 1 || l != 1) && (f != 1 || s != 1) && (l != 1 || f != 1))
                    changes = min(changes, st[index] != 'R' ? 1 : 0);
                
                return changes;
            }
            if (dp[index][sl][l] != -1)
                return dp[index][sl][l];
            int changes = 1e7; 
            if (sl != 0 || l != 0)
                changes = min(changes, (st[index] != 'L' ? 1 : 0) + g(index + 1, dp, l, 0, f, s, g));
            if (sl != 1 || l != 1)
                changes = min(changes, (st[index] != 'R' ? 1 : 0) + g(index + 1, dp, l, 1, f, s, g));

            return dp[index][sl][l] = changes;
        };
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {
                vector<vector<vec>> dp(n, vector<vec>(2, vec(2, -1)));
                int c1 = (i == 0 ? (st[0] != 'L') : (st[0] != 'R'));
                int c2 = (j == 0 ? (st[1] != 'L') : (st[1] != 'R'));

                ans = min(ans, g(2, dp, i, j, i, j, g) + c1 + c2);
            }
        }

        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}
