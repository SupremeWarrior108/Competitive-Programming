// https://cses.fi/problemset/task/1092

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
    ll n;  cin>>n;
    ll sum = (n*(n+1))/2;
    if(sum%2) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    vi a, b;
    ll f = 1, l = n;
    if(n%2==1){
        a.pb(1);
        a.pb(2);
        b.pb(3);
        f = 4;
    }
    while(f<l){
        if(f%2==1){
            a.pb(f);
            a.pb(l);
        }
        else{
            b.pb(f);
            b.pb(l);
        }
        f++;
        l--;
    }
    cout<<a.size()<<endl;
    for(auto x:a)   cout<<x<<sp;
    cout<<b.size()<<endl;
    for(auto x:b)   cout<<x<<sp;
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}