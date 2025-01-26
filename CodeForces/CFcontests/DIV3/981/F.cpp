// https://codeforces.com/contest/2033/problem/F

#include <bits/stdc++.h>
using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// Macros
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define up(v) upper_bound(v)
#define low(v) lower_bound(v)

// Read and Print
#define read(a, n) for (int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for (int i = 0; i < n; ++i) { cout << a[i] << " "; } cout << "\n";
#define endl "\n"
#define sp " "

// Typedefs
typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> plli;
typedef pair<int, int> pii;
typedef vector<lli> vi;
typedef vector<vector<lli>> vvi;
using vec = vector<int>;
#define int long long

// Constants
const int mod = 1e9 + 7;

void solve() {
    int t;  cin>>t;
    while(t--){
        int n, k; cin >> n >> k;
    
        if (k == 1){
            cout << (n % mod) << "\n";
            continue;
        }
        
        int t = 2;
        int f = 0, g = 1;
        while (true){
            int v = (f + g) % k;
            if (v == 0){
                break;
            }
            t++;
            f = g;
            g = v;
        }
        
        int ans = n % mod * t % mod;
        cout << ans << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0ll;
}