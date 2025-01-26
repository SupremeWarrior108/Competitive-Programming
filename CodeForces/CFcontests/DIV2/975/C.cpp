// https://codeforces.com/contest/2019/problem/C

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

// bool deck(ll mid, vi a, ll k){
//     ll coins= 0;
//     for(ll x: a){
//         if(x<mid){
//             coins+=(m-x);
//             if(c>k)     return false;
//         }
//     }
//     return true;
// }

void solve() {
    int t;  cin>>t;
    while(t--){
        ll n, k;   cin>>n>>k;
        vi a(n);
        // map<ll, ll> mp;
        for(ll i = 0; i<n; i++){
            cin>>a[i];
            // mp<a[i]>++;
        }
        ll sum = accumulate(all(a), 0), ans=0;
        for(ll i = 1; i<=n; i++){
            for(int j = 1; i<=k; k++){
                if(sum%i==0)    ans = max(ans, i);
                sum+=j;
            }
        }
        cout<<ans<<endl;
        // int n;
        // ll k;
        // cin>>n>>k;
        // vi a(n);
        // read(a, n);
        // ll maxn=*max_element(all(a));
        // // for(auto x:a){
        // //     maxn = max(maxn, x);
        // // }
        // ll total = accumulate(all(a), 0ll);
        // bool check = true;
        // for (int i = n; i > 0; i--) { 
        //     int q = (total + k) / i;
        //     if (q * i <= total - 1) continue; 
        //     if (q <= maxn - 1) continue;
        //     cout<<i<<endl;
        //     check = false;
        //     i=0;
        // }
        // if(check)   cout<<1<<endl;

        // // ll l = 0, r = 1e10;
        // // while(l<r){
        // //     ll mid = l + (r-l+1)/2;
        //     if(deck(mid, a, k))     l = mid;
        //     else    r = mid-1;
        // }
        // cout<<l<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}