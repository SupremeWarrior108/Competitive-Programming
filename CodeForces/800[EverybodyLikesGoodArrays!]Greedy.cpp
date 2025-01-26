// https://codeforces.com/problemset/problem/1777/A

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";
#define endl "\n"
#define sp " "

// Typedefs
typedef long long ll;
typedef vector <ll> vi;
using vec = vector<int>;

// Solve function
void solve() {
    int t;  
    cin >> t;
    while (t--) {
        int n;  
        cin >> n;
        vec a(n);
        read(a, n);

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            // Debugging: Print current pair being checked
            // cout << "Checking pair: " << a[i] << ", " << a[i + 1] << endl;
            
            if ((a[i] % 2 == 1 && a[i + 1] % 2 == 1) || (a[i] % 2 == 0 && a[i + 1] % 2 == 0)) {
                ans++;
                // cout << "Incremented ans to " << ans << " for pair: " << a[i] << ", " << a[i + 1] << endl;
            }
        }
        // cout << "Result for test case: " << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    solve();
    return 0;
}
