// https://www.codechef.com/practice/course/zco-inoi-problems/ZCOPRAC/problems/ZCO14002?tab=statement

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
    int n;  cin>>n;
    vec a(n);
    read(a, n);
    // int ans = 0;
    // int tmp = 1e4+5, cnt = 0, lastidx = 0;
    // int i;
    // for(i = 0; i<n; i++){
    //     tmp = min(tmp, a[i]);
    //     cnt++;
    //     if(cnt == 3){
    //         cnt = 0;
    //         // cout<<"tmp: "<<tmp<<"i "<<i<<endl;
    //         ans +=tmp;
    //         tmp = 1e4+5;
    //         lastidx = i;
    //     }
    // }
    // int bug = ans;
    // i--;
    // cout<<"i "<<i<<endl;
    // if(n%3==1){
    //     ans+=a[i];
    // }
    // else if(n%3==2){
    //     if(lastidx+cnt<n-1)   ans+=a[lastidx+cnt];
    //     else    ans+=min(a[lastidx+cnt], a[lastidx+cnt-1]);
    // }
    // cout<<ans-bug<<endl;
    if (n == 1) {
        cout << a[0] << endl;
        return;
    }
    if (n == 2) {
        cout << min(a[0], a[1]) << endl;
        return;
    }
    vec dp(n, -1);
    dp[n-1] = a[n-1];
    dp[n-2] = a[n-2];
    dp[n-3] = a[n-3];
    for(int i = n-4; i>=0; i--){
        dp[i] = a[i] + min({dp[i+1], dp[i+2], dp[i+3]});
    }
    cout<<min({dp[0], dp[1], dp[2]})<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}