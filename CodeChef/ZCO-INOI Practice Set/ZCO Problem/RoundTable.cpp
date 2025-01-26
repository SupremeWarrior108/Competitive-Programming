// https://www.codechef.com/practice/course/zco-inoi-problems/ZCOPRAC/problems/ZCO12004

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
    int n;  cin>>n;
    vec a(n);
    read(a, n);
    if (n <= 2) {
        cout << a[0] << endl;
        return;
    }
    vec dp(n, -1);
    vec dpp(n, -1);
    dp[n-1] = a[n-1];
    dp[n-2] = a[n-2];
    dpp[n-2]=a[n-2];
    dpp[n-3]=a[n-3];
    for(int i = n-3; i>0; i--){
        dp[i] = a[i] + min(dp[i+1], dp[i+2]);
    }
    for(int i = n-4; i>0; i--){
        dpp[i] = a[i] + min(dpp[i+1], dpp[i+2]);
    }
    // for(auto x:dp)  cout<<x<<endl;
    // cout<<endl;
    cout<<min(dp[2] + a[0], min(dp[1] + a[0],a[n-1]+dpp[1]))<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}