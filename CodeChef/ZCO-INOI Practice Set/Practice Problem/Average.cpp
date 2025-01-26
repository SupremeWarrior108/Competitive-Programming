// https://codechef.com/practice/course/zco-inoi-problems/IARCSJUD/problems/AVERAGE?tab=statement

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
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

void solve() {
    ll n; cin>>n;
    vi a(n);
    unordered_map<ll, ll> c;
    for(ll i = 0; i<n; i++){
        cin>>a[i];
        c[a[i]]++;
    }
    set<ll> avg;
    sort(all(a));
    ll cnt = 0;
    for(ll k = 0; k<n; k++){
        ll i = 0, j = n-1;
        while(i<j){
            if(i==k)    i++;
            else if(j==k)   j--;
            else{
                ll sum = a[i] + a[j];
                if(sum == 2*a[k]){
                    avg.insert(a[k]);
                    break;
                }
                else if(sum<2*a[k]) i++;
                else    j--;
            }
        }
    }
    cout<<cnt<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}