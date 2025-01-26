// https://oj.uz/problem/view/JOI21_ho_t2
// OI\JOI21\JOI21-Snowball.pdf

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
typedef pair <ll, ll> pii;
typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Solve

const ll N = 1e18;

void solve() {
    ll n, q;    cin>>n>>q;
    vi a(n+2);
    a[0] = -N;
    a[n+1] = N;
    for(int i = 1; i<=n; i++)   cin>>a[i];
    vi m(q+1), pref(q+1);
    map<ll, ll> mp;
    mp[0] = 0;
    for(ll i = 1; i<=q; i++){
        cin>>m[i];
        pref[i] += pref[i-1] + m[i];
        if(mp.find(pref[i])!=mp.end())  continue;
        if(pref[i]>0){
            auto it = mp.up(pref[i]);
            if(it==mp.end())    mp[pref[i]] = i;
        }
        else{
            auto it = mp.low(pref[i]);
            if(it==mp.begin())  mp[pref[i]] = i;
        }
    }
    for(ll i = 1; i<=n; i++){
        ll left = a[i], right = a[i];
        ll l = a[i-1], r = a[i];
        while(r-l>1){
            ll mid = (l+r)/2;
            ll x = mid - a[i];
            ll y = mid - a[i-1];
            auto it1 = mp.up(x);
            if(it1 == mp.begin()){
                l = mid;
                continue;
            }
            it1--;
            auto it2 = mp.low(y);
            if(it2 == mp.end()){
                r = mid;
                continue;
            }
            if((it1->ss)<(it2->ss)) r=mid;
            else l = mid; 
        }
        auto it1 = mp.up(r-1-a[i]);
        auto it2 = mp.low(r-a[i-1]);
        if(it1!=mp.begin()&&(it2==mp.end()||((--it1)->ss < it2->ss)))   r--;
        left = r;

        l = a[i];
        r = a[i+1];
        while(r-l>1){
            ll mid = (l+r)/2;
            ll x = mid - a[i];
            ll y = mid - a[i+1];
            it1 = mp.low(x);
            if(it1 == mp.end()){
                r = mid;
                continue;
            }
            it2 = mp.up(y);
            if(it2 == mp.begin()){
                l = mid;
                continue;
            }
            it2--;
            if((it1->ss)<(it2->ss)) l=mid;
            else r = mid; 
        }
        it1 = mp.low(l+1-a[i]);
        it2 = mp.up(l-a[i+1]);
        if(it1!=mp.end()&&(it2==mp.begin()||(it1->ss < (--it2)->ss)))   l++;
        right = l;it1 = mp.low(l+1-a[i]);
        cout<<right - left <<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}