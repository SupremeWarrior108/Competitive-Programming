// https://codeforces.com/contest/2024/problem/C

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
typedef vector <ll> vi;
typedef vector <vector <lli>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    int t;  cin>>t;
    while(t--){
        ll n;  cin>>n;
        vector<vi> a(n, vec(2, 0));
        vi val =(2*n);
        for(int i = 0; i<n; i++){
            cin>>a[i][0]>>a[i][1];
            val[2*i] = a[i][0];
            val[2*i+1] = a[i][1];
        }
        sort(all(val));
        map<ll, ll> mp;
        ll idx=1;
        for(ll i = 0; i<2*n; i++){
            if(mp.find(val[i]) == mp.end())
                mp[val[i]] = index++;
        }
    }
    vector<vi> b(n, vec(2, 0));
    for(ll i = 0; i<n; i++){
        b[i][0] = mp[a[i][0]];
        b[i][1] = mp[a[i][1]];
    }
    vector<vi> ans(n, vec(3, 0));
    for(int i = 0; i<n; i++){
        ll sum = b[i][0] + b[i][1];
        ans[i] = {sum, a[i][0], a[i][1]};
    }
    sort(all(ans));
    for(ll i = 0; i<n; i++) 
        cout<<ans[i][1]<<sp<<ans[i][2]<<sp;
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
