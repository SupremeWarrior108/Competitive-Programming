// https://atcoder.jp/contests/dp/tasks/dp_e

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
    int n, w;   cin>>n>>w;
    int items[n+1][2], dp[n+1][100001];
    for(int i =1; i<=n; i++)    cin>>items[i][0]>>items[i][1];

    for(int i = 0; i<=n; i++)
        for(int j = 0; j<=100000; j++)
            dp[i][j] = w+1;
    
    for(int i = 1; i<=n; i++){
        dp[i-1][0] = 0;
        for(int j = 1; j<=100000; j++){
            dp[i][j] = dp[i-1][j];
            if(j>=items[i][1]&&dp[i-1][j-items[i][1]]+items[i][0]<=w)
                dp[i][j] = min(dp[i][j], items[i][0]+dp[i-1][j-items[i][1]]);
        }
    }
    int ans= 0;
    for(int i =1; i<=100000; i++)
        if(dp[n][i]<=w) ans = i;
        cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}