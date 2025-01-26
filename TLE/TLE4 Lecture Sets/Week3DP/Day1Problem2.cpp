// https://codeforces.com/problemset/problem/1151/B

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
    int n, m;  cin>>n>>m;
    vector<vector<pii>> dp(n+1, vector<pii>(1024, {-1, -1}));
    vector<vec> a(n, vec(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>a[i][j];
        }
    }


    function<pii(int, int)> f=[&](int row, int k)->pii{
        if(row == n)    return {k!=0?1:0, -1};
        if(dp[row][k].ff!=-1)   return dp[row][k];
        dp[row][k].ff = 0;
        for(int i = 0; i<m; i++){
            if(f(row+1, k^a[row][i]).ff){
                dp[row][k]  = {1, i};
                break;
            }
        }
        return dp[row][k];
    };
    pii ans = f(0, 0);
    cout<<(ans.ff?"TAK":"NIE")<<endl;
    if(!ans.ff) return;
    int row = 0, k = 0;
    while(row<n){
        int ele = dp[row][k].ss;
        cout<<ele+1<<sp;
        int nr = row+1;
        int nk = k^a[row][ele];
        row = nr;
        k = nk;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}