//https://cses.fi/problemset/task/1753/

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i < n; ++i)
#define rrep(i, x, n)  for(int i = x; i >= n; --i)

// Read and Print
#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector<int> compute(const string& pattern){
    int m = pattern.length();
    vector<int> pi(m, 0);
    int k = 0;
    for (int i = 1; i < m; ++i){
        while (k > 0 && pattern[k] != pattern[i]){
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[i]){
            k++;
        }
        pi[i] = k;
    }
    return pi;
}

int KMP(const string& text, const string& pattern){
    int n = text.length();
    int m = pattern.length();
    if (m == 0 || n < m) return 0;
    vector<int> pi = compute(pattern);
    int count = 0;
    int q = 0;
    for (int i = 0; i < n; ++i){
        while (q > 0 && pattern[q] != text[i]){
            q = pi[q - 1];
        }
        if (pattern[q] == text[i]){
            q++;
        }
        if (q == m){
            count++;
            q = pi[q - 1];
        }
    }
    return count;
}

void solve() {
    string st, str; cin>>st>>str;
    
    cout<<KMP(st, str);
}

int main(){
    
    fast();
    solve();

    return 0;
}