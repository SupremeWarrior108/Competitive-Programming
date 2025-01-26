// https://cses.fi/problemset/task/2181

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
    ll n, m;   cin>>n>>m;
    vvi transition(1<<n);
    auto g = [&](ll ind, ll msk1, ll msk2, auto &&g)->void{
        if(ind > n)    return;
        if(ind == n){
            transition[msk1].pb(msk2);
            return;
        }
        //current block is 1
        g(ind+1, msk1+(1<<ind), msk2, g);

        //current block is 0
        g(ind+1, msk1, msk2 + (1<<ind), g);
        g(ind+2, msk1, msk2, g);
    };

    g(0, 0, 0, g);

    vvi dp(m, vi((1<<n), -1));
    
    auto f = [&](ll ind, ll msk, auto &&f)->ll{
            if(ind == m)    return (msk==0?1:0);
            if(dp[ind][msk]!=-1)    return dp[ind][msk];
            int ans = 0;
            for(auto x:transition[msk])
                ans = (ans + f(ind+1, x, f))%mod;
            dp[ind][msk] = ans;
    };
    
    cout<<f(0, 0, f);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}