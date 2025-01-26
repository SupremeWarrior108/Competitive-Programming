// https://cses.fi/problemset/task/2165

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

void solve() {
    vector<pii> ans;
    function<void(int, int, int, int)> recurse = [&](int n, int from, int to, int with) -> void{
        if(n==0)    return;
        recurse(n-1, from, with, to);
        ans.pb(make_pair(from, to));
        recurse(n-1, with, to, from);
    };
    int n;  cin>>n;
    recurse(n, 1, 3, 2);
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x.ff<<sp<<x.ss<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}