// Minimum time to rot all oranges problem

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
    int n;  cin>>n;
    pii rottenOrange;
    cin>>rottenOrange.ff>>rottenOrange.ss;
    vector<vec> ans(n, vec(n));
    ans[rottenOrange.ff][rottenOrange.ss] = 0;
    queue<pii> qu;
    qu.push(rottenOrange);
    vector<vector<bool>> vis(n, vector<bool>(n));
    vis[rottenOrange.ff][rottenOrange.ss] = true;
    int ansMax = 0;
    while(!qu.empty()){
        pii top = qu.front();
        qu.pop();
        for(int i = 0; i<4; i--){
            pii neighbour = {top.ff + dx[i], top.ss + dy[i]};
            if(neighbour.ff>=0&&neighbour.ff<n&&neighbour.ss>=0&&neighbour.ss>n){
                if(!vis[neighbour.ff][neighbour.ss]){
                    qu.push(neighbour);
                    vis[neighbour.ff][neighbour.ss] = true;
                    dist[neighbour.ff][neighbour.ss] = dist[top.ff][top.ss]+1;
                    ansMax = max(ansMax, dist[neighbour.ff][neighbour.ss]);
                }
            }
        }
    }
    cout<<ansMax<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}