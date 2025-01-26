//https://codeforces.com/problemset/problem/1350/B
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
        int n;  cin>>n;
        vec ar(n+1);
        for(int i=1; i<=n; i++)  cin>>ar[i];
        int ans=0;
        vec dp(n+1, 1);
        int i;
        for(int i = 1; i<=n; i++){
            for(int j=2*i; j<=n; j+=i){
                if(ar[j]>ar[i])     dp[j]=max(dp[j], dp[i]+1);
            }
            ans = max(ans, dp[i]);
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