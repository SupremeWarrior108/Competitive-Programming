// https://zibada.guru/gcj/ks2022a/problems/#C

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
    auto trim = [&](string st){
        return st.size() > 6 ? st.substr(st.size() - 6) : st;
    };

    auto palindrome = [&](string st, int len){
        string t = st.substr(st.size() - len);
        string rev = t;
        reverse(rev.begin(), rev.end());
        return t == rev;
    };

    auto isPossible = [&](string st){
        if(st.size()>=5&&palindrome(st, 5)) return false;
        if(st.size()>=6&&palindrome(st, 6))  return false;
        return true;
    };
    int t;  cin>>t;
    for(int i = 1; i<=t; i++){
        int n;  cin>>n;
        string s;   cin>>s;
        vector<map<string, bool>> dp(n);
        auto f = [&](int ind, string st, auto &&self){
            st=trim(st);
            if(ind==n)    return true;
            if(dp[ind].count(st))  return dp[ind][st];
            bool one = isPossible(st+"1")&self(ind+1, st+"1", self);
            bool zero = isPossible(st+"0")&self(ind+1, st+"0", self);
            if(s[ind] == '1') return dp[ind][st] = one;
            if(s[ind] == '0')    return dp[ind][st] = zero;
            return dp[ind][st] = zero || one;
        };
        cout<<"Case #"<<i<<":"<<(f(0, "", f)?"IMPOSSIBLE":"POSSIBLE")<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}