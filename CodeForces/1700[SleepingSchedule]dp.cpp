// https://codeforces.com/problemset/problem/1324/E

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
typedef vector <vector <lli>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    int n, h, l, r; cin>>n>>h>>l>>r;
    vec a(n+1);
    for(int i = 1; i<=n; i++)   cin>>a[i];
    vector<vec> dp(n+1, vec(h, -mod));
    dp[0][0]=0;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<h; j++){
            dp[i][j] = max(dp[i-1][(j-a[i]+1+h)%h], dp[i-1][(j-a[i]+h)%h]);
            if(j>=l&&j<=r&&dp[i][j]!=-mod)  dp[i][j]++;
        }
    }
    int ans = 0;
    for(int j = 0; j<h; j++){
        ans = max(ans, dp[n][j]);
    }
    cout<<ans<<endl;
}   


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}