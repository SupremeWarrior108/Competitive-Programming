/*
    Assume that there is an hypothetical DP state

    Transition:
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + .... + dp[1] + dp[0]

    Base Case:
        dp[0] = 1;

    Final Subproblem:
        dp[n]
    
    assume 0<n<1e9
*/

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
typedef vector <vector <ll>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    /*
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + .... + dp[1] + dp[0]
        dp[i-1] = dp[i-2] + dp[i-3] + .... + dp[1] + dp[0]

        dp[i] = 2*dp[i-1]
        dp[i] = 2^i     //use binary exponential
    */
   ll n; cin>>n;
   ll ans;
   base = 2;
   while(n>0){
        if(n%2==1)  ans = (ans * base) % mod;
        base = (base * base)%mod;
        n/=2;
   }
   cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}