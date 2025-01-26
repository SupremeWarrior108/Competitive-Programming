// https://codeforces.com/contest/2025/problem/D

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
typedef long long int lli;
typedef long double ld;
typedef pair <lli, lli> plli;
typedef pair <int, int> pii;
typedef vector <lli> vi;
typedef vector <vector <lli>> vvi;
using vec = vector<int>;

// Constants
const lli mxn = 1e6 + 5;
const lli mod = 1e9 + 7;

// Solve

void solve() {
    lli n,m;
    cin>>n>>m;
 
    vi dp(m+1,-1e18);
    dp[0]=0;
 
    auto diff = [&]()->void{
        for(lli i=m;i>0;i--)
            dp[i]=dp[i]-dp[i-1];
    };
 
    auto make = [&]()->void{
        for(lli i=1;i<=m;i++)
            dp[i]+=dp[i-1];
    };
 
    diff();
 
    lli total = 0;
 
    auto add=[&]()->void{
        make();
        total++;
        for(lli i=m;i>0;i--)
            dp[i]=max(dp[i],dp[i-1]);
 
        diff();
    };
 
    while(n--){
        lli r;
        cin>>r;
        if(r==0){
            add();
            continue;
        }
        if(r>0){
            dp[r]++;
            continue;
        }
        r=total-abs(r);
        if(r<0)
            continue;
        dp[0]++;
        if(r<m)
            dp[r+1]--;
        continue;
    }
 
    make();
    cout<<*max_element(all(dp))<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}