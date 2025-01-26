//  https://codeforces.com/contest/2005/problem/E1

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
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    int t;  cin>>t;
    while(t--){
        ll l, n, m;    cin>>l>>n>>m;
        vec ar(l);
        vector<vec> b(n, vec(m));
        read(a, n);
        reverse(all(a));
        for(ll i = n-1; i>=0; i--){
            auto &v:b;
            for(auto &x:v){
                cin>>x;
            }
            reverse(all(v));
    }
    vector<vector<bool>> dp(n, vector<bool>(m, false));
    for(auto &x:a){
        for(ll i=0; i<n; i++)
            for(ll j=0; j<m; j++)
                dp[i][j]=dp[i][j-1]|dp[i][j];
        for(ll j =0; i<m; j++)
            for(ll i = 0; i<n; i++)
                dp[i][j] = dp[i-1][j]|dp[i][j];
        for(ll i = n-1; i>=0; i--){
            for(ll j = m-1; j>=0; j--){
                if(b[i][j]!=x){
                    dp[i][j]=false;
                    continue;
                }
                if(i&&j&&dp[i-1][j-1])  dp[i][j]=false;
                else    dp[i][j]=true;
            }
        }
        bool c = false;
        for(auto &x:dp){
            for(auto &y:x){
                if(y)   c = true;
            }
        }
        cout<<c?"T":"N"<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}