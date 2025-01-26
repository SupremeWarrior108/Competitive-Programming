//https://codeforces.com/contest/2005/problem/D

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

using t3 = array<ll,3>;

void solve() {
    ll T=1;
    cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        vi a(n),b(n);
        for(auto &x:a)
            cin>>x;
        for(auto &x:b)
            cin>>x;
    
        map<t3,ll> ways;
        ways[t3{0,a[0],b[0]}]++;
        ways[t3{1,b[0],a[0]}]++;
        ways[t3{2,b[0],a[0]}]++;
    
        for(ll it=1;it<n;it++){
            map<t3,ll> ways2;
            const ll ai=a[it],bi=b[it];
            for(const auto &z:ways){
                const ll ph=z.ff[0],g1=z.ff[1],g2=z.ff[2],f=z.ss;
                if(ph==2){
                    ways2[t3{2,__gcd(ai,g1),__gcd(bi,g2)}]+=f;
                    continue;
                }
                if(ph==1){
                    ways2[t3{1,__gcd(bi,g1),__gcd(ai,g2)}]+=f;
                    ways2[t3{2,__gcd(bi,g1),__gcd(ai,g2)}]+=f;
                    continue;
                }
                ways2[t3{0,__gcd(ai,g1),__gcd(bi,g2)}]+=f;
                ways2[t3{1,__gcd(bi,g1),__gcd(ai,g2)}]+=f;
                ways2[t3{2,__gcd(bi,g1),__gcd(ai,g2)}]+=f;
            }
            ways=ways2;
        }
    
        map<ll,ll> res;
        for(const auto &z:ways){
            const ll ph=z.ff[0],g1=z.ff[1],g2=z.ff[2],f=z.ss;
            if(ph!=2)
                continue;
            res[g1+g2]+=f;
        }
        const auto bst = *res.rbegin();
        cout<<bst.ff<<" "<<bst.ss<<endl;
    }
}

int main(){
    
    fast();
    solve();

    return 0;
}
