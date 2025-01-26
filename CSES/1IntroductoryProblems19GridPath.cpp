#include <bits/stdc++.h>
 
using namespace std;
 
// Macros
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
 
// Read and Print
#define read(a, n) for (ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for (ll i = 0; i < n; ++i) { cout << a[i] << " "; } cout << "\n";
 
#define endl "\n"
#define sp " "
 
// Typedefs
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair < ll, ll > pll;
typedef pair < lli, lli > plli;
typedef pair < int, int > pii;
typedef vector < lli > vi;
typedef vector < vector < lli >> vvi;
using vec = vector < int >;
 
// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;
 
 
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
 
// Solve
void solve() {
    string s;
    int n, ans;
    int visited[12][12];
    auto f = [&](int x, int y, int & i, auto && f) -> void {
        if ((visited[x][y - 1] && visited[x][y + 1]) &&
            (!visited[x - 1][y] && !visited[x + 1][y]))
            return;
        if ((visited[x - 1][y] && visited[x + 1][y]) &&
            (!visited[x][y - 1] && !visited[x][y + 1]))
            return;
 
        if (x == 7 && y == 1) {
            if (i == n) ans++;
            return;
        }
 
        if (i == n) return;
        visited[x][y] = 1;
        
        if (s[i] == '?') {
            for (int j = 0; j < 4; ++j) {
                int px = x + dx[j];
                int py = y + dy[j];
                if (!visited[px][py]) {
                    i++;
                    f(px, py, i, f);
                    i--;
                }
            }
        } else {
            int px = x, py = y;
            if (s[i] == 'L') py--;
            else if (s[i] == 'R') py++;
            else if (s[i] == 'U') px--;
            else px++;
 
            if (!visited[px][py]) {
                i++;
                f(px, py, i, f);
                i--;
            }
        }
        visited[x][y] = 0; 
    };
    cin >> s;
    n = s.size();
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < 10; i++) {
        visited[0][i] = 1;
        visited[i][0] = 1;
        visited[8][i] = 1;
        visited[i][8] = 1;
    }
 
    ans = 0;
    int step = 0;
    f(1, 1, step, f);
    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}