/*
Given a grid NxM 
print path from (0, 0) to (N-1, M-1) that has min sum
you can only do down (i+1, j) and right(i, j+1)!!
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
    int n, m;   cin>>n>>m;
    vector<vec> a(n, vec(m)), dp(n, vec(m, -1));
    for(auto x:a){
        for(auto y:x)   cin>>y;
    }
    function<int(int, int)> f = [&](int i, int j)->int{
        if(i==n-1&&j==m-1)  return dp[i][j] = a[i][j];
        if(i==n||j==m)  return MAX_INT;
        if(dp[i][j]!=-1)    return dp[i][j];
        return dp[i][j] = a[i][j] + min(dp[i+1][j], dp[i][j+1]);
    };
    //now answer construction:     either store the choice you made or backtrack

    //backtracking solution
    int i = 0, j = 0;
    while(i<n&&j<m){
        cout<<a[i][j]<<sp;
        if(dp[i][j] == a[i][j] + dp[i+1][j])    i++;
        else    j++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}