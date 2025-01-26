// https://oj.uz/problem/view/JOI18_stove
// OI\JOI18-Stove.pdf

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

void solve() {
    int n, k;   cin>>n>>k;
    vi a(n);
    vi diff(n-1);
    cin>>a[0];
    read(a, n);
    sort(all(a));
    for(int i =0; i<n-1; i++){
        diff[i] = a[i+1]-a[i]-1;
    }
    sort(rall(diff));
    ll ans = a[n-1]-a[0]+1;
    for(int i = 0;i<k-1; i++){
        if(diff[i]>0)   ans-=diff[i];
    }
    cout<<ans<<endl;    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}