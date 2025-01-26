// https://codeforces.com/contest/2033/problem/B#

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
#define up(v)       upper_bound(v)
#define low(v)      lower_bound(v)

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
typedef long long int lli;
typedef pair <ll, ll> pll;
typedef pair <lli, lli> plli;
typedef pair <int, int> pii;
typedef vector <lli> vi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    int t;  
    cin >> t; 
    while(t--) {
        int n;  
        cin >> n; 
        vector<vec> a(n, vec(n, 0)); 
        for(auto &x : a) {
            for(auto &y : x) {
                cin >> y; 
            }
        }

        ll cnt = 0; 

        for(int d = 0; d < n; d++) {
            int i = 0, j = d;
            int minh = INT_MAX; 
            while(i < n && j < n) {
                minh = min(minh, a[i][j]);
                i++;
                j++;
            }
            if(minh < 0) {
                cnt += -minh;
            }
        }

        
        for(int d = 1; d < n; d++) {
            int i = d, j = 0;
            int minh = INT_MAX;
            while(i < n && j < n) {
                minh = min(minh, a[i][j]);
                i++;
                j++;
            }
            if(minh < 0) {
                cnt += -minh;
            }
        }
        cout << cnt << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}