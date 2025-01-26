// https://www.codechef.com/practice/course/zco-inoi-problems/IARCSJUD/problems/TILES01

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
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

int m = 15746;

int recur(int i, vec &dp){
    if(i==1||i==0) return 1;
    if(dp[i]!=-1)   return dp[i];
    dp[i] = (recur(i-1, dp)+recur(i-2, dp))%m;
    return dp[i];
}

void solve() {
    int n;  cin>>n;
    vec dp(n+1, -1);
    dp[1]=1;
    cout<<recur(n, dp)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}