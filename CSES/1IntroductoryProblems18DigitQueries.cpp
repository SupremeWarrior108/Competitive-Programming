// https://cses.fi/problemset/task/2431

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
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector <ll> vi;
typedef vector <vi> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    int t;  cin>>t;
    while(t--){
        ll n, ans = 0; cin >> n;
        if (n <= 9)cout << n << endl;
        else {
            vector<ll> v;
            v.pb(9);
            ll x = 0, c = 1;
            while (x < 1e18) {
                x = v.back() + (9ll * powl(10, c) * (c + 1));
                c++;
                v.pb(x);
            }
            ll sz = lower_bound(all(v), n) - v.begin();
            sz++;
            string s = ""; n -= v[sz - 2];
            while (s.size() != sz) {
                ll l = s.size(), x = sz * powl(10, sz - l - 1);
                if (s.size() == 0) {
                    ll y = 0, xx = x;
                    for (int i = 1; i <= 9; i++) {
                        if (xx >= n) {
                            y = i; xx -= x; n -= xx;
                            break;
                        }
                        xx += x;
                    }
                    s += (y + '0');
                }
                else {
                    ll y = 0, xx = x;
                    for (int i = 0; i <= 9; i++) {
                        if (xx >= n) {
                            y = i; xx -= x; n -= xx;
                            break;
                        }
                        xx += x;
                    }
                    s += (y + '0');
                }
            }
            cout << s[n - 1] << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}