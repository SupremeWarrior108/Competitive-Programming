// https://atcoder.jp/contests/dp/tasks/dp_i

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
    int n;  cin>>n;
    vector<ld> p(n);
    read(p, n);
    vector<vector<ld>> dp (n, vector<ld>(n+1, 0));
    dp[0][0] = 1-p[0];
    dp[0][1] = p[0];
    for(int  i = 1; i<n; i++){
        for(int j = 0; j<=i+1; j++){
            if(j!=0)    dp[i][j] = dp[i-1][j]*(1-p[i]) + dp[i-1][j-1]*p[i];
            else    dp[i][0] = dp[i-1][0]*(1-p[i]);
        }
    }
    ld ans = 0;
    for(int i = n/2+1; i<=n; i++){
        ans+=dp[n-1][i];
    }
    cout<<fixed << setprecision(10)<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}