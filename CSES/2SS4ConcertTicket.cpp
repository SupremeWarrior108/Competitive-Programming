// https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
#define up       upper_bound
#define low      lower_bound

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
typedef long long int lli;
typedef pair <ll, ll> pll;
typedef pair <lli, lli> plli;
typedef pair <int, int> pii;
typedef vector <ll> vi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e18+6; 

// Solve

void solve() {
    int n, m;
    cin>>n>>m;
    multiset<int> a;
    vec ticket(n);
    vec cus(m);
    for(int i = 0; i<n; i++){
        cin>>ticket[i];
        a.insert(ticket[i]);
    }
    read(cus, m);
    for (int i = 0; i < m; i++){
        auto match = a.lb(cus[i]+1);
        if(match == a.begin())
            cout<<-1<<endl;
        else{
            match--;
            cout<<(*match)<<endl;
            a.erase(match);
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
