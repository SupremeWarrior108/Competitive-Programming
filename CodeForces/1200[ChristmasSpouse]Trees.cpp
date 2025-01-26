// https://codeforces.com/problemset/problem/913/B

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

bool check(vec &parrent,vec &notleaf,int n){
	bool flag = true ;
	vec v(n+1);
	for(int i = 2 ; i <= n; i++){
		if(notleaf[i]==false){
			v[parrent[i]] ++;
		}
	}
	
	for(int i = 1 ; i <= n ; i++)
		if(notleaf[i] and v[i] < 3){
			flag = false;
			break ;
		}
	return flag ;
}

void solve() {
    int n; cin>>n;
    vec parent(n+1), notleaf(n+1);
    int temp=0;
    for(int i=2;i<=n; i++){
        cin>>temp;
        parent[i]=temp;
        notleaf[temp]++;
    }    
    if(check(parent, notleaf, n))   cout<<"Yes";
    else    cout<<"No";
}

int main(){
    
    fast();
    solve();

    return 0;
}