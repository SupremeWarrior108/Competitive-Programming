//https://codeforces.com/problemset/problem/2010/C1

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
    string st; cin>>st;
    int i=0,j=1;
	while(j<st.length()){
		if(st[i]==st[j]){i++,j++;}
		else {j-=i-1;i=0;}
	}
	if(i>j-i){
		cout<<"YES"<<endl;
		cout<<st.substr(0,i)<<endl;
	}
	else cout<<"NO"<<endl;
}

int main(){
    
    fast();
    solve();

    return 0;
}