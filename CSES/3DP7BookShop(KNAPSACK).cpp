//https://cses.fi/problemset/task/1158

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

// Solve

void solve() {
    int n,x;
    cin>>n>>x;

    vector<int> page(n),price(n);
    int a,b;

    for(int&i : price)
    cin>>i;

    for(int&i : page)
    cin>>i;

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j >= price[i-1])
            {
                dp[i][j] = max (dp[i][j],dp[i-1][j-price[i-1]] + page[i-1]); //max of both the boxes included in dp[i][j]. 
            }
        }
    }

    cout<< dp[n][x] <<endl;
}

int main(){
    
    fast();
    solve();

    return 0;
}