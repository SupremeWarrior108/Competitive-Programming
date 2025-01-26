// https://www.codechef.com/practice/course/zco-inoi-problems/IARCSJUD/problems/DIVSEQ?tab=solution

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
    int n;  cin>>n;
    vec a(n);
    read(a, n);
    int cnt = 1;
    vec dp(n+1, 1);
    for(int i = n-1; i>=0; i--){
        for(int j = i+1; j<n; j++){
            if(a[j]%a[i]==0)    dp[i] = max(dp[i], dp[j]+1);
        }
        cnt = max(cnt, dp[i]);
    }
    cout<<cnt<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}