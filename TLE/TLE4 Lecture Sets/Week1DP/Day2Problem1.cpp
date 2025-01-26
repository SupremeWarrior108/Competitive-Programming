/*
    There is a list of n numbers and two players who move alternately. On each move, a player removes either the first or last number from the list, and their score increases by that number. Both players try to maximize their scores.
    What is the maximum possible score for the first player when both players play optimally?
    Input
    The first input line contains an integer n: the size of the list.
    The next line has n integers x_1,x_2,\ldots,x_n: the contents of the list.
    Output
    Print the maximum possible score for the first player.
    Constraints

    1 \le n \le 5000
    -10^9 \le x_i \le 10^9

    Example
    Input:
    4   
    4 5 1 3

    Output:
    8
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

#define rep(i, x, n)   for(int i = x; i < n; ++i)
#define rrep(i, x, n)  for(int i = x; i >= n; --i)

// Read and Print
#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

int sum(vector<vector<int>>* a, int i, int j){
    int s=0;
    for(int k=i; k<=j; k++) s+=a[k];
    return s;
}

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    vector<vector<int> dp(vector<int>(n,-1));
    read(a, n);
    for(int i=n-1; i>=0; i--){
        dp[i][i]=a[i];
        for(int j=i+1; j<n; j--){
            dp[i][j]=max(a[i]+sum(a, i+1, j)-dp[i+1][j], a[j]+sum(a, i. j-1)-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1];
}
int main(){
    
    fast();
    solve();

    return 0;
}