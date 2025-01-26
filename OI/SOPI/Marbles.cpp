#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
#define up(v)       upper_bound(v)
#define low(v)      lower_bound(v)

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
typedef long long int lli;
typedef pair <ll, ll> pll;
typedef pair <lli, lli> plli;
typedef pair <int, int> pii;
typedef vector <lli> vi;
typedef vector <vector <lli>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

ll solve() {
    int n, k;
    cin>>n>>k;
    k--;
    n--;
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    ll ans = 1;
    if (k > n - k) {
        k = n - k;
    }
    for (int i = 1; i <= k; ++i) {
        ans = ans * (n - (k - i)) / i;
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
    return 0;
}