// https://atcoder.jp/contests/dp/tasks/dp_o

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
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    int n; cin>>n;
    vector<vec> a(n, vec(n)), dp(n, vec(1<<n, -1));
    auto f = [&](int ind, int msk, auto &&f){
        if(ind == n)    return 1;
        if(dp[ind][msk]!=-1)    return dp[ind][msk];
        int ways = 0;
        for(int i = 0; i<n; i++){
            if(((1<<i)&msk) == 0 && a[ind][i])     
                ways = (ways + f(ind + 1, msk + (1<<i), f))%mod;
        }
        return dp[ind][msk] = ways;
    };
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>a[i][j];
        }
    }
    cout<<f(0, 0, f);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}