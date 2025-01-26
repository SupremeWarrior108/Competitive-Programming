// https://codeforces.com/contest/2021/problem/B

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

void solve() {
    int t;  cin>>t;
    while(t--){
        int n, x;   cin>>n>>x;
        map<int, int> mp;
        vec a(n);
        for(auto x:a){
            cin>>x;
            mp[x]++;
        }
        
        // for(auto x:mp)  cout<<x.ff<<sp;
        
        int ans = 0;

        while(true){
            if(mp[ans]==0){
                cout<<ans<<endl;
                break;
            }
            if(mp[ans]>1){
                mp[ans+x]+=mp[ans]-1;
            }
            ans++;
        }
        // cout<<ans<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}