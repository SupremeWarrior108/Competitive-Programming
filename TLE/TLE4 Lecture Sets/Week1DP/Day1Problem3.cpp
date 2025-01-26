/*
    Given an array of integers (both positive and negative) .
    Pick a subsequence of elements from it such that no 2 adjacent
    elements are picked and the sum of picked elements is maximized.
*/

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

int f(int index){
    if(index<0) return 0;
    if(dp[index]!=-mod) return dp[index]
    dp[index]=max(dp[index]+f(index-2),f(index-1));
    return dp[index];
}

void solve() {
    int n; cin>>n;
    vector<int> a(n), dp(n, -mod);
    read(a, n);
    cout<<f(n-1)<<endl;
}
int main(){
    
    fast();
    solve();

    return 0;
}