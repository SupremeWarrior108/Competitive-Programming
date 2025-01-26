//  https://codeforces.com/contest/2014/problem/A

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
    int t;  cin>>t;
    while(t--){
        int n, k;   cin>>n>>k;
        // cout<<"n: "<<n<<" k: "<<k<<endl;
        vector<int> a(n);
        read(a, n); 
        int robin = 0, count =0;
        for(int i = 0; i<n; i++){
            // cout<<"a["<<i<<"]: "<<a[i]<<endl;
            // cout<<(a[i]>=k)<<endl;
            if(a[i]>=k){
                robin +=a[i];
                continue; 
            }
            // cout<<"robin "<<robin<<endl;
            // cout<<"a[i]=0&&robin!=0 "<<(a[i]=0&&robin!=0)<<endl;
            if(a[i]==0&&robin!=0){
                // cout<<"hi"<<endl;
                robin--;
                count++;
            }
        }
        cout<<count<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}