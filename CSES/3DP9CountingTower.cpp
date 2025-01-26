// https://cses.fi/problemset/task/2413

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
    int t;  cin>>t;
    vector<vi> dp(1e6+1, vi(3, -1));
    while(t--){
        ll n;  cin>>n;
            auto f = [&](ll w, ll h, auto &&f)->ll{
            if(h==1)    return 1;
            if(dp[h][w]!=-1)    return dp[h][w];
            if(w==1)    dp[h][w] = (4*f(1, h-1, f)+f(2, h-1, f))%mod;
            else    dp[h][w] = (2*f(2, h-1, f)+f(1, h-1, f))%mod;
            return dp[h][w];
        };
        cout<<(f(1, n, f)+f(2, n, f))%mod<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}