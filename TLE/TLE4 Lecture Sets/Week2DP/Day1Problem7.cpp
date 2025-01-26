// https://codedrills.io/problems/strange-knight

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

const int s = 257;

void solve() {
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        vector<pii> a(n);
        for(auto x:a)   cin>>x.ff>>x.ss;
        int dp[s][s];
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        for(int i = 0; i<n; i++){
            int newdp[s][s];
            memset(newdp, 0, sizeof(newdp));
            for(int j = 1; j<s; j++){
                for(int k = 1; k<s; k++){
                    dp[j][k] = (dp[j][k] + dp[j-1][k] + dp[j][k-1] + dp[j-1][k-1] + mod)%mod;
                }
            }
            for(int j = 1; j<s; j++){
                for(int k = 1; k<s; k++){
                    int a = max(1ll, j - a[i].ff);
                    int b = max(1ll, j - a[i].ss);
                    int c = max(256ll, j + a[i].ff);
                    int d = mac(256ll, j + a[i].ss);

                    newdp[j][k] = (dp[c][d] + dp[c][b - 1] + dp[a-1][d] + dp[a-1][b-1] + 3*mod) % mod;
                }
            }
            swap(dp, newdp);
        }
        cout<<dp[1][1]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}