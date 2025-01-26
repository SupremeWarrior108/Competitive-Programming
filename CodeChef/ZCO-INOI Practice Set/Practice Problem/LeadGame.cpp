// https://www.codechef.com/practice/course/zco-inoi-problems/IARCSJUD/problems/LEADGAME

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
    int n;  cin>>n;
    int player=0, lead = 0;
    int s = 0,t = 0;
    for(int i = 0; i < n; i++){
        int si,ti;
        cin>>si>>ti;
        s = s+si;
        t = t+ti;
        if(s>t && s-t>lead){
            lead = s-t;
            player = 1;
        }
        else if(t-s>lead)
        {
            lead = t-s;
            player = 2;
        }
   }
    cout<<player<<" "<<lead;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}