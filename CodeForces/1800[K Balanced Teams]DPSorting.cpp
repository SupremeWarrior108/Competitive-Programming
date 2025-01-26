// https://codeforces.com/problemset/problem/1133/E

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
    int n, k;   cin>>n>>k;
    vec a(n), ind(n);
    read(a, n);
    sort(all(a));
    for(int i = 0. j = 0; i<n; i++){
        while(j<n&&a[j]-a[i]<=5)    j++;
        ind[i] = j-1;
    }
    vector<vec> dp(n, vec(k+1, -1));
    auto f = [&](int i, int m, auto &&f)->int{
        if(i==n||m==k)   return 0;
        if(dp[i][m]!=-1)    return dp[i][m];
        return dp[i][m] = max(f(i+1, m, f), ind[i]-i+1+f(ind[i]+1, m+1, f));
    };
    cout<<f(0, 0, f)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}