/*
    Problem 2

    Given a 2d Grid (NxM) with numbers written in each cell.
    Find the path from top left(0,0) to bottom right(n,m) with minimum sum of values of path.
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

#define rep(i, x, n)   for(int i = x; i < n; ++i)
#define rrep(i, x, n)  for(int i = x; i >= n; --i)

// Read and Print
#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}


vector<vector<int>> grid(n, vector<int>(m)), dp(n, vector<int>(m));

// Solve
int f(int i, int j){
    if(i>=n||j>=m)  return 1e9;
    if(i==n-1&&j==m-1)  return grid[i][j];
    if(dp[i][j]!=-1)    return dp[i][j];
    dp[i][j]=grid[i][j]+min(f(i, j+1), f(i+1, j));
    return dp[i][j];
}
void solve() {
    int n, m; cin>>n>>m;
    for(int =0; i<n; i++)
        for(int j = 0; j<m; j++){
            cin>>a[i][j];
            dp[i][j]=-1;
        }
    cout<<f(0, 0)<<endl;
}

int main(){
    
    fast();
    solve();

    return 0;
}