// https://codeforces.com/contest/1722/problem/A

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

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    int t;  cin >> t;
    string target = "Timur";
    sort(target.begin(), target.end());  // Sort the target string once

    while (t--) {
        int len;  cin >> len;
        string name;  cin >> name;

        if (len == 5) {  // "Timur" is of length 5
            sort(name.begin(), name.end());  // Sort the input string
            if (name == target)  // Compare sorted strings
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}