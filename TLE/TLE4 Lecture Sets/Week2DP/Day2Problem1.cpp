/*
Given an array of 3s, 5s and question marks, find the maximum score you
can get by replacing each question mark with a 3 or a 5, such that there
is a score associated with each index based on whether it contains a 3 or
a 5. You cannot use more than k1 3s and k2 5s in the complete array.
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
    ll n, k1, k2; cin>>n>>k1>>k2;
    vec three, five;
    vector<string> a;
    read(a, n);
    read(three, n);
    read(five, n);

    // stardard solution -> without state optimization: O(n^3) call this function with f(0, 0, 0)
    // 
    // vector<vector<vec>> dp(n, vector<vec>(k1, vec(k2, -1)));
    // function<ll(ll, ll, ll)> f = [&](ll i, ll j, ll k)->ll{
    //     if(j>k1||k>k2)  return -mod;
    //     if(i==n)    return 0;
    //     if(dp[i][j] != -1)  return dp[i][j];
    //     if(a[i] == '?') dp[i][j][k] = max(three[i] + f(i+1, j+1, k), five[i] + f(i+1, j, k+1));
    //     else if(a[i] == '3') dp[i][j][k] = three[i] + f(i+1, j+1, k);
    //     else    dp[i][j][k] = five[i] + f(i+1, j, k+1);
    //     return dp[i][j][k;]
    // };
    // cout<<f(0, 0, 0)<<endl;

    // observation for state optimization
    // when i-th step is proceeded, k = i - j or j = i - k

    vector<vi> dp(n, vi(k1, -1));
    function<ll(ll, ll)> f = [&](ll i, ll j)->ll{
        ll k = i - j;
        if(j>k1||k>k2)  return -mod;
        if(i==n)    return 0;
        if(a[i] == '?') dp[i][j] = max(three[i] + f(i+1, j+1), five[i] + f(i+1, j));
        if(dp[i][j]!=-1)    return dp[i][j];
        else if(a[i] == '3') dp[i][j] = three[i] + f(i+1, j+1);
        else    dp[i][j] = five[i] + f(i+1, j);
        return dp[i][j];
    };
    cout<<f(0, 0)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}