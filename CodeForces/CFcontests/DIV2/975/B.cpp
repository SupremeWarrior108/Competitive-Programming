// https://codeforces.com/contest/2019/problem/B

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

// vi fac(ll n){
//     vi fac;
//     for (ll i = 1ll; i <= sqrt(n); ++i) {
//         if (n % i == 0) {
//             fac.pb(i);
//             if (i != n / i) {  // To avoid adding the square root twice if it's a perfect square
//                 fac.pb(n / i);
//             }
//         }
//     }
//     return fac;
// }

void solve() {
    // int t;  cin>>t;
    // while(t--){
    //     int n, q;   cin>>n>>q;
    //     vi x(n);
    //     read(x, n);
    //     // sort(all(a));
    //     // vi gaps(n-1);
    //     // for(int i = 0; i<n-2; i++){
    //     //     gaps[i] = x[i+1]-x[i]i1;
    //     // }
    //     // sort(rall(gaps));
    //     ll totalpt = x[n-1]-x[0]+1;
    //     for(int i = 0; i<q; i++){
    //         ll k;   cin>>k;
    //         // if(k==1)    cout<<totalpt<<sp;
    //         // else if(k>n-1)  cout<<0<<sp;
    //         // else{
    //         //     for(int i =0; i<k-1; i++)   totalpt -= gaps[i];
    //         //     cout<<totalpt<<sp;
    //         // }
    //         // cout<<endl;
    //         if()
    //     }
    // }
    int t;  cin>>t;
    while(t--){
        ll n, q;    cin>>n>>q;
        vi a(n);
        read(a, n);
        map<ll, ll> mp;
        for(ll i =0; i<n; i++){
            ll tmp = (i+1)*(n-i)-1;
            mp[tmp]++;
            if(i>0){
                ll tmp2 = (n-i)*i;
                mp[tmp2]+=a[i]-a[i-1]-1;
            }
        }
        while(q--){
            ll k;   cin>>k;
            if(mp.find(k)==mp.end())    cout<<0<<sp;
            else    cout<<mp[k]<<sp;
        }
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}