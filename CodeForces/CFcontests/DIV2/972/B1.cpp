//https://codeforces.com/contest/2005/problem/B1

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

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

void solve() {
    int t;  cin>>t;
    while(t--){
        int n, m, q;    cin>>n>>m>>q;   //m=2, q=1
        vec a(m);
        for(auto &x:a){
            cin>>x;
        }
        sort(all(a));
        while(q--){
            ll c;   cin>>c;
            if(c<a[0]){
                cout<<a[0]-1<<"\n";
                continue;
            }  
            if(c>a[1]){
                cout<<n-a[1]<<"\n";
                continue;
            }
            ll mid = (a[0]+a[1])/2;
            ll t1 = mid-a[0];
            ll t2 = a[1]-mid;
            cout<<min(t1, t2)<<"\n";
        }
    }
}

int main(){
    
    fast();
    solve();

    return 0;
}