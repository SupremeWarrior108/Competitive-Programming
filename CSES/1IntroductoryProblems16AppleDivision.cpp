// https://cses.fi/problemset/task/1623

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
typedef pair <ll, ll> pii;
typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

ll recur(int idx, vi& arr, ll sum1, ll sum2, ll n){
    if(idx == n){
        return abs(sum1-sum2);
    }
    ll choose = recur(idx + 1, arr, sum1 + arr[idx], sum2, n);
    ll notChoose = recur(idx + 1, arr, sum1, sum2 + arr[idx], n);
    return min(choose, notChoose);
}

void solve() {
    int n;  cin>>n;
    vi a(n);
    read(a, n);
    cout<<recur(0, a, 0 , 0 , n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}