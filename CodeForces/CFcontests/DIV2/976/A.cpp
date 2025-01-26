// https://codeforces.com/contest/2020/problem/0

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

void solve() {}
    int t;  cin>>t;
    while(t--){
        ll l = 1, r = 1e15+15, ans = 0;
        while(l<=r){
            ll mid = (l+r)/2;
            ll a = sqrt(mid);
            while(t*t>mid)  t--;
            while((t+1)*(t+1)<=mid) t++;
            ll count = mid-t;
            if(count>=n){
                ans = mid;
                r = mid-1;
            }
            else    l=mid+1;

        }
        cout<<ans<<endl;

    //     ll n, k;   cin>>n>>k;
    //     ll ans = 0;
    //     while(n){
    //         if(k==1){
    //         ans+=n;
    //         break;
    //         }
    //         if(n%k==0){
    //         ans+=1;
    //         break;
    //         }
    //         else{
    //             ans++;
    //             int x;
    //             for(int i = 2; n>pow(k, i); i++)    x=pow(k, i);
    //             n-=x;
    //         }
    //     }
    //     cout<<ans<<endl;
    // }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}