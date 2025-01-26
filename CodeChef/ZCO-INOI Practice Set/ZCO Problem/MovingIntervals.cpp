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
#define debug(x)    cout << #x << "=" << x << endl;

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
    int c, n, k;
    cin>>c>>n>>k;
    vector<pii> a(n);
    ll sum = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i].ff>>a[i].ss;
        sum+=a[i].ss-a[i].ff+1;
    }
    sort(all(a));
    // for(auto x:a)   cout<<"1st "<<x.ff<<sp<<"2nd "<<x.ss<<endl;
    int ind = -1;
    bool chk = true;
    for(int i = 1; i<n; i++){
        if(a[i-1].ss>=a[i].ff){
            ind = i;
            chk = false;
            break;
        }
    }
    auto f = [&](int index) -> bool{
        int len = a[index].ss - a[index].ff +1 , end = 0, gap = 0;
        for(int i = 0; i<n; i++){
            if(i == index)  continue;
            if(end >= a[i].ff)  return false;
            gap = max(gap, a[i].ff - end - 1);
            end = max(end, a[i].ss);
        }
        gap = max(gap, c-end);
        return gap>=len;
    };
    if(k == 0){
        if(chk) cout<<"Good"<<endl;
        else    cout<<"Bad"<<endl;
    }
    else{
        if(chk) cout<<"Good"<<endl;
        else
            cout<<((f(ind) || f(ind-1))?"Good":"Bad")<<endl;
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
    // cout<<t<<endl;
  while (t--) {
    solve();
  }
  return 0;
}