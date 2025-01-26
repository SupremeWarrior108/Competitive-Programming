#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define mp          make_pair
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
#define up          upper_bound
#define low         lower_bound
#define read(a, n)  for (ll i = 0; i < n; ++i)  cin >> a[i];
#define print(a, n) for (ll i = 0; i < n; ++i) {  cout << a[i] << " ";    } cout << "\n";
#define endl        "\n"
#define sp          " "
#define v           vector
#define debug(x)    cout << #x << "=" << x << endl;

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
    int n = 500 + 7;
    ll dp[n][n];
    bool chk[n][n];
    vvi grid;
    v<v<bool>> charms;
    cin>>n;
    int m;
    cin>>m;
    grid.assign(n, vi(n, 0));
    for(auto &x:grid){
        for(auto &y: x) cin>>c;
    }
    charms.assign(n, v<bool>(n, false));
    auto f = [&](int i, int j, int k)->void{
        int si = i - k, sj = j - k;
        int ei = i + k, ej = j + k;
        si = si<0?0:si;
        sj = sj<0?0:sj;
        ei = ei>n-1?n-1:ei;
        ej = ej>n-1?n-1:ej;
        for(int r = si; r<=ei; r++){
            for(int c = sj; c<=ej; c++)
            if(abs(i-r)+abs(c-j)<=k)
                charms[r][c] = true;
        }
    };
    for(int i = 0; i<m; i++){
        int x, y, k;
        cin>>x>>y>>k;
        f(x-1, y-1, k);
    }
    auto g = [&](int i, int j, auto&& g)->ll{
        if(i<0 || j<0)  return INT_MIN;
        if(charms[i][j]==false) return INT_MIN;
        if(chk[i][j])   return dp[i][j];
        if(i==0 && j == 0)  return grid[i][j];
        int a = g(i-1, j, g);
        int b = g(i, j-1, g);
        if(max(a, b)!=INT_MIN)  dp[i][j] = max(a, b) + grid[i][j];
        else    dp[i][j] = INT_MIN;
        ready[i][j] = true;
        return dp[i][j];
    };  
    g(n-1, n-1);
    if(ans == INT_MIN)  cout<<"NO"<<endl;
    else    cout<<"YES"<<endl<<ans<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}