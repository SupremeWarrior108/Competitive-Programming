// https://codeforces.com/contest/2014/problem/B

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


using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

ll sum(int x){
    return x*(x+1)/2;
}

void solve() {
    int t;  cin>>t;
    while(t--){
        ll n, k;   cin>>n>>k;
        ll max = 0;
        ll start = max(1LL, n-k+1);
        ll total = sum(n)-sum(start-1);
        // for(int i = max(1, n-k+1); i<=n; i++)
        //     max+=i;

        cout<<((total%2==0)?"YES":"NO")<<endl;
    }   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}