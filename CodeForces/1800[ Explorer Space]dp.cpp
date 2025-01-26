// https://codeforces.com/contest/1517/problem/D

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
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e18+6; 

// Solve

bool valid(int i, int j, int n, int m){
    return (i>=0 && i<n && j>=0 && j<m);
}

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<vec> hoz(n, vec(m-1));
    vector<vec> ver(n-1, vec(m));
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m-1; j++)
            cin>>hoz[i][j];
    for(int i = 0; i<n-1; i++)
        for(int j = 0; j<m; j++)
            cin>>ver[i][j];
    vector<vector<vec>> dp(n, vector<vec>(m, vec(21, INT_MAX)));
    vec dx = {0, 0, 1, -1};
    vec dy = {1, -1, 0, 0};
    for(int a = 0; a<=20; a++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(a&1) dp[i][j][a] = -1;
                else{
                    if(a == 0) dp[i][j][a] = 0;
                    else{
                        dp[i][j][a] = INT_MAX;
                        for(int c = 0; c<4; c++){
                            int newx = i + dx[c];
                            int newy = j + dy[c];
                            if(valid(newx, newy, n, m)){
                                int wt = 0;
                                if(newx != i)   wt = ver[min(newx, i)][j];
                                else    wt = hoz[i][min(newy, j)];
                                dp[i][j][a] = min(dp[i][j][a], dp[newx][newy][a-2] + 2 * wt);
                            }
                        }
                    } 
                }
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<dp[i][j][k]<<sp;
        }
        cout<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
