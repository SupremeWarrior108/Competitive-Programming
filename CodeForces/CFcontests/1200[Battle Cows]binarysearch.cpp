// https://codeforces.com/problemset/problem/1951/B

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
const ll INF = 1e18+6; 

// Solve

void solve() {
    int t;  cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        k--;
        vec a(n);
        read(a, n);
        auto it = find_if(all(a), [&](int v) {
            return v > a[k];
        });
        int x = *(it - a.begin());
        vec pos(n);
        iota(all(a), 0);
        int ans = 0;
        for(int i: {0, x}){
            if(i==n)    continue;
            swap(pos[i], pos[k]);
            vec st(n);
            for (int j = 1, u = pos[0]; j < n; j++) {
                int v = pos[j];
                u = (a[u] > a[v] ? u : v);
                st[u]++;
            }
            swap(pos[i], pos[k]);
            ans = max(ans, stt[k]);
        }
        cout<<ans<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
