// https://codeforces.com/contest/2014/problem/D

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
    int t;  cin>>t;
    while(t--){
        int n, d, k;    cin>>n>>d>>k;
        vec a(n+2, 0);
        for(int i = 0 ; i<k; i++){
            int l, r;   cin>>l>>r;
            a[l]++;
            a[r+1]--;
        }
        vec overlap(n+1, 0);
        for(int i = 0; i<=n; i++){
            a[i]+=a[i-1];
            overlap[i] = a[i];
        }
        int p =-1, bro=1;
        for (int i = 1; i <= n - d + 1; i++) {
            int c = 0;
            for (int j = i; j < i + d; j++) {
                c += overlap[j];
            }
            if (c > p) {
                p = c;
                bro = i;
            }
        }
        int mino = INT_MAX;
        int mom= 1;

        for (int i = 1; i <= n - d + 1; i++) {
            int c = 0;
            for (int j = i; j < i + d; j++) {
                c += overlap[j];
            }
            if (c < mino) {
                mino = c;
                mom = i;
            }
        }

        cout << bro << " " << mom<< endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}