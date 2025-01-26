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

// Solve

void solve() {
    ll T=1;
cin>>T;
while(T--)
{
    ll l,n,m;
    cin>>l>>n>>m;
    vi a(l);
    vector<vi> b(n,vi(m));
    for(auto &x:a)
        cin>>x;
    reverse(all(a));
 
    for(ll j=n-1;j>=0;j--){
        auto &v=b[j];
        for(auto &x:v)
            cin>>x;
        reverse(all(v));
    }
 
    set<ll> valA;
    for(const auto &x:a)
        valA.insert(x);
 
    vec ncur;
    auto keepBest = [&](vec &cur)->void{
        vi firstVal(n,m);
        for(const auto &x:cur)
            firstVal[x.ff]=min(firstVal[x.ff],x.ss);
 
        cur.clear();
        for(ll i=0;i<n;i++)
            if(firstVal[i]<m)
                cur.eb(i,firstVal[i]);
 
    };
 
    map<ll,vec> cells;
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++){
            if(valA.count(b[i][j]))
                cells[b[i][j]].eb(ii{i,j});
        }
 
    for(auto &v:cells)
        keepBest(v.ss);
 
    vec winPos;
    for(const auto &cur:a){
 
        vi smallWinCol(n,m);
        for(const auto &x:winPos)
            smallWinCol[x.ff]=min(smallWinCol[x.ff],x.ss);
 
        for(ll i=1;i<n;i++)
            smallWinCol[i]=min(smallWinCol[i],smallWinCol[i-1]);
 
        winPos.clear();
        for(const auto &x:cells[cur]){
            const ll r=x.ff,c=x.ss;
            if(r==0){
                winPos.eb(r,c);
                continue;
            }
 
            if(smallWinCol[r-1]<c)
                continue;
            winPos.eb(r,c);
        }
    }
 
    cout<<(winPos.empty()?"N":"T")<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}