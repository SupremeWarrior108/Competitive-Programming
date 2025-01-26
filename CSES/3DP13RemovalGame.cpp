//  https://cses.fi/problemset/task/1097

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define mp          make_pair
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
#define up          upper_bound
#define low         lower_bound
#define read(a, n)  for (ll i = 0; i < n; ++i)  cin >> a[i];
#define print(a, n) for (ll i = 0; i < n; ++i) {  cout << a[i] << " ";    } cout << "\n";
#define endl        "\n"
#define sp          " "
#define v           vector
#define debug(x)    cout << #x << "=" << x << endl;

// #define rep(i, x, n)   for(int i = x; i < n; ++i)
// #define rrep(i, x, n)  for(int i = x; i >= n; --i)

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

void solve(){
    int n;
    cin>>n;
    vi a(n);
    vvi dp(n, vi(n));
    ll total = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        dp[i][i] = a[i];
        total += a[i];
    }
    for(int i = n-1; i>=0; i--){
        for(int j = i+1; j<n; j++){
            ll first = a[i] - dp[i+1][j];
            ll last = a[j] - dp[i][j-1];
            dp[i][j] = max(first, last);
        }
    }
    cout<<(total + dp[0][n-1])/2<<endl;
}

int main(){
    
    fast();
    solve();

    return 0;
}