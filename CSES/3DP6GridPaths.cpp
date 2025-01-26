//  https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define rep(i, x, n) for (int i = x; i < n; ++i)
#define rrep(i, x, n) for (int i = x; i >= n; --i)

// Read and Print
#define read(a, n)             \
    for (ll i = 0; i < n; ++i) \
        cin >> a[i];
#define print(a, n)            \
    for (ll i = 0; i < n; ++i) \
    {                          \
        cout << a[i] << " ";   \
    }                          \
    cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

// Solve
char matrix[1001][1001];

void solve(){
    int n;
    cin >> n;
    vi pre(n);
     for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    if (matrix[0][0] == '*'){
        cout << 0 << endl;
        return;
    }
    pre[0] = 1;
    for (int i = 1; i < n; i++){
        pre[i] = pre[i - 1];
        if (matrix[0][i] == '*')
            pre[i] = 0;
        }
    for (int i = 1; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j == 0){
                if (matrix[i][j] == '*')
                    pre[j] = 0;
            }
            else if (matrix[i][j] == '*'){
                pre[j] = 0;
            }
            else{
                pre[j] = (pre[j - 1] + pre[j]) % mod;
            }
        }
    }
    cout << pre[n - 1] << endl;
}

int main(){

    fast();
    solve();

    return 0;
}