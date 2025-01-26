// https://atcoder.jp/contests/dp/tasks/dp_f

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
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    string s, t;    cin>>s>>t;
    vector<vec> dp(s.size(), vec(t.size(), -1));
    function<int(int, int)> f = [&](int i, int j) -> int{
        if(i==s.size() || j==t.size())  return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        if(s[i] == t[j])    return dp[i][j] = 1 + f(i+1, j+1);
        return dp[i][j] = max(f(i+1, j), f(i, j+1));
    };
    f(0, 0);
    int x = 0, y = 0;
    while(x<s.size()&&y<t.size()){
        if(s[x]==t[y]){
            cout<<s[x];
            x++;
            y++;
        }
        else if(x+1<s.size()&&dp[x][y] == dp[x+1][y])   x++;
        else if(y+1<t.size()&&dp[x][y] == dp[x][y+1])   y++;
        else    break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}