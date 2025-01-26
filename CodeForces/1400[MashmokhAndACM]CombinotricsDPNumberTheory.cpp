//https://codeforces.com/contest/414/problem/B

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i < n; ++i)
#define rrep(i, x, n)  for(int i = x; i >= n; --i)

// Read and Print
#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;


using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    ll n, k;    cin>>n>>k;
    vector<vector<ll>> dp(k+1, vector<ll>(n+1));
    int i, j;
    rep(i, 1, n+1)     dp[k][i]=1;
    
    rrep(i, k-1, 0){
        rep(j, 1, n+1){
            for(int m = j; m<=n; m+=j){
                dp[i][j]=(dp[i][j]+dp[i+1][m])%mod;
            }
        }
    }
    cout<<dp[0][1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}