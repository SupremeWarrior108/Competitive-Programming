// Find out the minimum and maximum area of an island on a binary matrix

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
    vec dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    int n;  cin>>n; //assuming NxN grid
    vector<vec> a(n);
    for(auto &x:a) 
        for(auto &y:x)  cin>>y;

    map<pii, vector<pii>> edges;
    set<pii> valid;
    map<pii, bool> vis;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j]==1){
                valid.insert({i, j});
                for(int k = 0; k<4; k++){
                    int newx = i + dx[k], newy = j + dy[k];
                    if(newx>=0&&newx<n&&newy>=0&&newy<n){
                        if(grid[newx][newy] == 1){
                            edges[{i, y}].pb({newx, newy});
                        }
                    }
                }
            }
        }
    }  
    // now simple dfs code
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}