// https://www.codechef.com/practice/course/zco-inoi-problems/ZCOPRAC/problems/ZCO14002?tab=statement

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
    if (n == 1) {
        cout << a[0] << endl;
        return;
    }
    if (n == 2) {
        cout <<a[0] + a[1] << endl;
        return;
    }
    vector<vec> dp(n, vec(3, 0));
    dp[0][1] = dp[0][2] = dp[1][0] = dp[1][1] = a[0];
    dp[1][2] = a[0] + a[1];
    for(int i = 2; i<n; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        dp[i][1] = a[i] + dp[i-1][0];
        dp[i][2] = a[i] + a[i-1] + dp[i-2][0];
    }
    cout<<max({dp[n-1][0], dp[n-1][1], dp[n-1][2]})<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}