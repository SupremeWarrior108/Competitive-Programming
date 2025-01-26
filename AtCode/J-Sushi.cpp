// https://atcoder.jp/contests/dp/tasks/dp_j


/*
    Solution->
    dp[i][j][k][l] = exp moves to eat all sushis such that there are
    i plates of 0 shushi
    j plates of 1 shushi
    k plates of 2 shushi
    l plates of 3 shushi

    state eliminatio to optimize form O(N^4) -> o(N^3):
    i + j + k + l = n
    i = n - j - k - l

    Cyclic transition:
    dp(i, j, k, l) = i/n(1+dp(i, j, k, l)) + j/n(1+dp(i+1, j-1, k, l))+ k/n(1+dp(i, j+1, k-1, l))
                            l/n(1+dp(i, j, k+1, l-1))

    on simplification:
    dp(i, j, k, l) = 1/n-i [(i + j(1+dp(i+1, j-1, k, l)) + k(1+dp(i, j+1, k-1, l)) + l(1+dp(i,j,k+!,l-1)))

    on adding state optimization with transition

    i = n - j - k - l
    dp(j, k, l) = (i + j(1+dp(j-1, k, l)) + k(1+dp(j+1, k-1, l)) + l(1+dp(j, k+1, l-1)))/n-i

    final subproblem: dp(no. of 1s, no. of 2s, no. of 3s)
*/


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
    int n, size = 303;  cin>>n;
    int ar[4];
    memset(ar, 0, sizeof(ar));
    vec a(n);
    for(auto x:a){
        cin>>x;
        ar[x]++;
    }
    vector<vector<vector<double>>> dp(size, vector<vector<double>>(size, vector<double>(size, -1)));
    function<double(int, int, int)> f = [&](int i, int j, int k)->double{
        if(i == 0 && j == 0 && k == 0) return 0;
        if(i<0 || j<0 || k<0)   return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int l = n - (i + j + k);
        return dp[i][j][k] =  (l + i*(1+f(i-1, j, k)) + j*(1+f(i+1, j-1, k))+ k*(1+f(i, j+1, k-1)))/(n-l);
    };
    cout<<setprecision(50)<<f(ar[1], ar[2], ar[3])<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}