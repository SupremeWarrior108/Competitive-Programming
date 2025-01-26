// https://www.codechef.com/practice/course/zco-inoi-problems/ZCOPRAC/problems/ZCO14001

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
#define up(v)       upper_bound(v)
#define low(v)      lower_bound(v)

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
typedef vector <lli> vi;
typedef vector <vector <lli>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    ll n, h;    cin>>n>>h;
	vi a(n+1, 0);
	for(ll i = 1; i<=n; i++)   cin>>a[i];
	ll pos = 1; 
	bool hook = false;
	while(true){
	    int op; cin>>op;
	    if(op == 0) break;
	    if(op==1 && pos!=1)   pos--;
	    else if(op==2 && pos!=n)    pos++;
	    else if(op==3 && a[pos]!=0&&!hook){
	        a[pos]--;
	        hook = true;
	    }
	    else if(op==4 && a[pos]!=h&&hook){
	        a[pos]++;    
	        hook = false;
	    }
	}
	for(int i = 1; i<=n; i++)   cout<<a[i]<<sp;
	cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}