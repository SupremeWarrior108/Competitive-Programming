//https://codeforces.com/contest/2005/problem/C

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

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

string st = "narek";
set<char> crs = {'n', 'a', 'r', 'e', 'k'};

void solve() {
    ll t; cin>>t;
    while(t--){
        ll n, m; cin>>n>>m;
        vector<string> a(n);
        read(a, n);
        vector<vec> dp(n+1, vec(5, -mod));
        dp[0][0]=0;
        for(ll i = 1; i<=n; i++){
            auto &s = a[i-1];
            dp[i]= dp[i-1];
            for(int j =0; j<5; j++){
                ll c = dp[i-1][j];
                ll k = j;
                for(auto &x: s){
                    if(crs.count(x))    c--;
                    if(st[k]==x) k++;
                    if(k==5){
                        c+=10;
                        k=0;
                    }
                }
                dp[i][k] = max((ll)dp[i][k], c);
            }

        }
        ll ans = *max_element(all(dp[n]));
        cout << ans << endl;
    }
}

int main(){
    
    fast();
    solve();
    return 0;
}