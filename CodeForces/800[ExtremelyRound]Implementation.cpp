// https://codeforces.com/problemset/problem/1766/A

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
#define sp " "

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

set<int> can;

bool check(int i){
    int cnt = 0;
    while(i>0){
        int d = i%10;
        if(d!=0)    cnt++;
        i/=10;
    }
    return cnt == 1;
}

void solve() {
    int t;  cin>>t;
    for(int i = 0; i<1e7; i++){
        if(check(i))
            can.insert(i);
    }
    while(t--){
        int n;  cin>>n;
        int cnt = 0;
        for(auto it:can){
            if(it<=n)   cnt++;
        }
        cout<<cnt<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}