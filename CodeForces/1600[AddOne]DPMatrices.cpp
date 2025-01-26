// https://codeforces.com/problemset/problem/1513/C

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
    int maxm = 2*10e5+5;
    int t;  cin>>t;
    vector<vi> dp(maxm, vi(10, 0));
    for(int i = 0; i<10; i++)   dp[0][i] = 1;
    for(int i = 1; i<maxm; i++){
        for(int j = 0; j<9; j++){
            dp[i][j] = (dp[i-1][j+1]);
        }            
        dp[i][9] = (dp[i-1][0]+dp[i-1][1])%mod;
    }
    while(t--){
        string s;
        int m;
        cin>>s>>m;
        ll ans = 0;
        for(auto i : s){
            // cout<<"ans: "<<ans<<endl;
            ans = (ans+dp[m][i-'0'])%mod;
        }
        cout<<ans<<endl;
    }   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}