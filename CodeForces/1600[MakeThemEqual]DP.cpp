// https://codeforces.com/contest/1633/problem/D

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
#define endl "\n"

// Typedefs
typedef long long ll;
typedef vector<int> vec;

// Constants
const int mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve
void solve() {
    int t;  
    cin >> t;
    const int s = 1001;
    vec req(s, 1e9);
    req[1] = 0;

    for(int i = 1; i < s; i++) {
        for(int x = 1; x <= i; x++) {
            if (i / x > 0) {
                int j = i + i / x;
                if (j < s) {
                    req[j] = min(req[j], req[i] + 1);
                }
            }
        }
    }

    while(t--) {
        int n, k;   
        cin >> n >> k;
        vec b(n), c(n);
        for(auto &x : b) cin >> x;
        for(auto &x : c) cin >> x;

        k = min(k, 12 * n); 
        vec dp(k + 1, 0);

        for(int i = 0; i < n; i++) {
            for(int j = k - req[b[i]]; j >= 0; j--) { 
                dp[j + req[b[i]]] = max(dp[j + req[b[i]]], dp[j] + c[i]);
            }
        }
        cout << *max_element(all(dp)) << endl; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    solve();

    return 0;
}
