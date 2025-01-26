// https://www.codechef.com/practice/course/zco-inoi-problems/IARCSJUD/problems/LONGPALI

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
    string st, str = "";  cin>>st;
    auto check = [](string st, int i, int j)->bool{
        while(i<j){
            if(st[i]!=st[j])    return false;
            i++;
            j--;
        }
        return true;
    };
    int len = 0;
    for(int i  =0; i<n; i++){
        for(int j = 0; j<n; j++){
            string s = st.substr(i, j-i+1);
            if(check(s, 0, s.length()-1)&&s.length()>len){
                len = s.length();
                str = s;
            }
        }
    }
    cout<<len<<endl<<str<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}