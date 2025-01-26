// https://cses.fi/problemset/task/1755

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
    string s;   cin>>s;
    vec a(26);
    for(int i =0; i<s.size(); i++){
        a[s[i] - 'A']++;
    }
    int odds=0, oddi = -1;
    for(int i = 0; i<26; i++){
        if(a[i]%2){
           odds++;
           oddi = i;
        }
    }
    if(odds>1){
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    for(int i = 0; i<26; i++){
        if(a[i]%2==0){
            int half = a[i]/2;
            a[i]-=half;
            while(half--)   cout<<(char)('A' + i);
        }
    }
    if(oddi!=-1){
        while(a[oddi]--)    cout<<(char)('A'+oddi);
    }
    for(int i = 25; i>=0; i--){
        while(a[i]>0){
            a[i]--;
            cout<<(char)('A'+i);
        }
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}