// https://codeforces.com/contest/2022/problem/C

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
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        vector<string> vote(2);
        cin>>vote[0]>>vote[1];
        vec dp(n+1, 0);
        for(int i = 0; i<n; i+=3){
            int ca = 0, cj = 0;
            for(int j = 0; j<3; j++){
                if(vote[0][i+j]=='A')   ca++;
                else    cj++;
                if(vote[1][i+j]=='A')   ca++;
                else    cj++;
            }
            int x = (ca>=2?1:0);
            dp[i+3] = max(dp[i+3], dp[i]+x);
        }
        cout<<dp[n]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}