// Given a positive integer N <= 1e6, at every step the following 3 things
// can happen to N with equal probability.
// - N = N / 2
// - N = N - 1
// - N remains unchanged
// Find expected number of steps it will take to convert for N to become 0


// Solution-->
// Cyclic DP state elimination-->
// dp[i] = 1/3(1+dp[i-1])+1/3(1+dp[i/2]) + 1/3(1+dp[i])
// on simplification
// dp[i] = (3+dp[i-1]+dp[i/2])/2
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
    int n;  cin>>n;
    vec dp(n, -1);
    function<int(int)> f=[&](int i)->int{
        if(i==0)    return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = (3+f(i-1)+f(i/2))/2;
    };
    cout<<f(n)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}