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

// Read and Print
#define read(a, n) for (ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for (ll i = 0; i < n; ++i) { cout << a[i] << " "; } cout << "\n";
#define endl "\n"
#define sp " "

// Typedefs
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair <ll, ll> pll;
typedef pair <lli, lli> plli;
typedef pair <int, int> pii;
typedef vector <ll> vi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e18 + 6;

bool div(const string& num) {
    int s = 0, alt = 0;
    bool isEven = (num.back() - '0') % 2 == 0;

    for (int i = 0; i < num.size(); ++i) {
        int d = num[i] - '0';
        s += d;
        alt += (i % 2 == 0 ? d : -d);
    }

    return (s % 3 == 0) && (alt % 11 == 0) && isEven;
}

// Memoization map
map<string, string> memo;

string findSmallest(int n, string cur) {
    if (cur.size() == n) {
        return div(cur) ? cur : "";
    }

    // Check if the result is already computed
    string key = to_string(n) + "|" + cur; // Unique key for current state
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    string s = findSmallest(n, cur + '3');
    if (!s.empty()) return memo[key] = s;

    string t = findSmallest(n, cur + '6');
    if (!t.empty()) return memo[key] = t;

    return memo[key] = ""; 
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string ans = findSmallest(n, "");
        if (ans.empty()) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
