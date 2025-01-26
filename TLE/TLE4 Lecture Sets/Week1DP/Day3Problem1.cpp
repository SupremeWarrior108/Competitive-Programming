// https://codeforces.com/problemset/problem/1881/E

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
typedef pair <ll, ll> pii;
typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 6;
const ll mod = 1e9 + 7;

// Solve


// vec a(mxn, -1);   
// vec dp(mxn, -1);
int n;

int recur(int i, vec &a, vec &dp){
    if(i>=n)    return 0;
    if(dp[i]!=-1)   return dp[i];
    if(i==n-1)  return 1;
    // if(i+a[i]>n-1)   return n-i;
    ll pick = mxn, dont = mxn;
    if(i+a[i]<n)    pick = recur(i+a[i]+1, a, dp);
    dont = recur(i+1, a, dp);
    dp[i] = min(pick, dont + 1);
    return dp[i];
}

void solve() {
    int t;  cin>>t;
    while(t--){
        cin>>n;
        vec a(n), dp(n, -1);
        read(a, n);
        cout<<recur(0, a, dp)<<endl;
        // a;
        // dp;
        // dp[n-1]=1;
        // for(int i = 0; i<n; i++){
        //     if(i+a[i]<n)    dp[i]=min(dp[i+a[i]+1], dp[i+1]+1);
        //     else    dp[i]=dp[i+1]+1;
        // }
        // dp.erase(all(dp));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}