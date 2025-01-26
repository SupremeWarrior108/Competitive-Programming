//  https://cses.fi/problemset/task/1633

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

void solve() {
	int n;
	cin>>n;
    vector<int> dp(n+1);
    read(dp, n);
    dp[0]=1;
   for(int i=1; i<=n; i++){
   	for(int j=1; j<=6; j++){
   		if(j<=i)	
   			dp[i]=(dp[i]+dp[abs(i-j)])%mod;
   	}
   } 
   cout<<dp[n]<<endl;
}

int main(){
    
    fast();
    solve();

    return 0;
}