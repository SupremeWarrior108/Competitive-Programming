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
 
// Read and Print
#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";
#define endl "\n"
#define sp " "
 
// Typedefs
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll> pll;
typedef pair<lli, lli> plli;
typedef pair<int, int> pii;
typedef vector<ll> vi;
typedef vector<vector<lli>> vvi;
using vec = vector<int>; 
 
// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;
 
// Solve
const ll N = 1e5 + 5;
const ll INF = 1e18 + 6;
 
struct data{
    ll c, f, p;
};
 
void solve(){
    ll n, m, sum=0;
    vector<struct data> a;
    cin>>n;
    for(ll i = 1; i<=n; i++){
        ll c, f, p;
        cin>>c>>f>>p;
        a.pb({c, f, -p});
        sum+=c;
    }
    cin>>m;
    for(ll j = 0; j<m; j++){
        ll c, f, p;
        cin>>c>>f>>p;
        a.pb({-c, f, p});
    }
    vector<vi> dp(sum + 1, vi(2, -INF));
    dp[0][0] = 0;
    
    auto comp = [&](struct data &a, struct data &b) -> bool {
        return a.f != b.f ? a.f > b.f : a.p < b.p;
    };
    sort(all(a), comp);
    for(ll i = 0; i<a.size(); i++){
        for(ll j = 0; j<=sum; j++)
            dp[j][1] = dp[j][0];
        for(ll j = 0; j<=sum; j++){
            ll pre = j - a[i].c;
            if(pre>=0 && pre<=sum && dp[pre][0] != -INF)
                dp[j][1] = max(dp[j][1], dp[pre][0] + a[i].p);
        }
        for(ll j = 0; j<=sum; j++)
            dp[j][0] = dp[j][1];
    }
    ll ans = -INF;
    for(ll i = 0; i<=sum; i++)
        ans = max(ans, dp[i][0]);
    cout<<ans<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    solve();
    return 0;
}