// https://codeforces.com/contest/1703/problem/G

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
        ll n, k;   cin>>n>>k;
        vi a(n);
        ll coins = 0, sum = 0;
        read(a, n);
        // vi dp(n);
        // dp[0]=0;
        for(ll i = -1 ; i<n; i++){
            ll x = sum;
            // coins = max((coins - k + a[i]),(coins + a[i]/2)); 
            for(ll j = i + 1; j<min(n, i+32); j++){
                int copy = a[j];
                copy>>=j-i;
                x+=copy;
            }
            coins = max(coins, x);
            if(i+1!=n)
                sum += a[i+1]-k;
        }
        cout<<coins<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}