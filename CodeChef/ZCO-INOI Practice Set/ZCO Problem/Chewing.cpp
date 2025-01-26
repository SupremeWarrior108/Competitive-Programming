// https://www.codechef.com/practice/course/zco-inoi-problems/ZCOPRAC/problems/ZCO13003?tab=statement

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
typedef vector <lli> vi;
typedef vector <vector <lli>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    ll n, k;   cin>>n>>k;
    vi a(n+1);
    read(a, n+1);
    sort(all(a));
    // ll ans = 0;
    // ll idx = (lower_bound(a.begin(), a.begin()+n, k)-a.begin());
    // n = idx;
    // cout<<"idx: "<<idx<<endl;
    // for(int i = 0; i<n; i++){
    //     ll tmp = a[i];
    //     auto it = lower_bound(a.begin(), a.begin()+n, k-a[i]-1);
    //     if(it!=a.begin()+n||it!=a.end()){
    //         ll  index =  (it-a.begin());  
    //         cout<<"index; "<<index<<endl;
    //         ans+=index;
    //     }
    // }
    
    // // int j = n;
    // // for(int i = 0; i<n; i++){
    // //     while(a[i]+a[j]>=k&&j>0)
    // //         j--;
    // //     if(j>i) 
    // //         ans+=(j-i+1);
    // //     else break;
    // // }
    // cout<<ans<<endl;
    ll ans = 0,j = n;
    for(int i = 1; i<=n; i++){
        while(a[i] + a[j] >= k&&j>0)    j--;
        if(j>i) ans+=j-i;
        else    break;
    }
    cout<<ans<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}