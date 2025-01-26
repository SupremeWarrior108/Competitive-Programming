#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
#define up          upper_bound
#define low         lower_bound

// Read and Print
#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";
#define endl "\n"
#define sp " "

// Typedefs
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair <ll, ll> pll;
typedef pair <lli, lli> plli;
typedef pair <int, int> pii;
typedef vector <ll> vi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e18 + 6; 

// Solve
bool cmp(int x, int y, int z) { 
    if (z > 30) return 1; 
    return x < y * (1LL << z); 
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n; 
        vec a(n); 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        vector<pii> val; 
        ll ans = 0; 
        vi pow2(n * 32 + 1); 
        pow2[0] = 1; 
        for (int i = 1; i <= n * 32; i++) pow2[i] = pow2[i - 1] * 2 % mod; 
        for (int i = 0; i < n; i++) { 
            int x = a[i], y = 0; 
            while (x % 2 == 0) x /= 2, y++; 
            while (!val.empty() && cmp(val.back().ff, x, y)) { 
                ans = (ans - val.back().ff * pow2[val.back().ss] % mod + mod) % mod; 
                ans = (ans + val.back().ff) % mod; 
                y += val.back().ss; 
                val.pop_back(); 
            } 
            val.pb({x, y}); 
            ans = (ans + val.back().ff * pow2[val.back().ss]) % mod; 
            cout << ans <<sp; 
        } 
        cout << endl; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
