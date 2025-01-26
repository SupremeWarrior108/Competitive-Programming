// modified rotten orange, multiple oranges

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

bool dfs(int curr, vecotr<vec>& edges, vec& color){
    bool possible = true;
    for(int neighbour : edges[curr]){
        if(color[neighbour] == 0){
            color[neighbour] = color[curr] == 1?2:1;
            possible = possible&&dfs(neighbour, edges, color);
        }
        else if(color[neighbour] == color[curr])    possible= false;
    }
    return possible
}

void solve() {
    int n, m;   cin>>n>>m;
    vector<vec> edges(n, vec());
    for(int i = 0; i<m; i++){
        int a, b;   cin>>a>>b;
        a--;
        b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    vec color(n, 0);
    bool possible = true;
    for(int i = 0;  i<n && possible; i++){
        if(color[i]!=0) continue;
        color[i] = 1;
        possible = possible && dfs(i, edges, color);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}