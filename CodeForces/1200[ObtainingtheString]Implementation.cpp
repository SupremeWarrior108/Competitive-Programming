//https://codeforces.com/contest/1015/problem/B

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

int flag=0;
int moves[10005],cnt=0;
int n;

string reshape(string s, int i, int pos){
    for( ;i>pos;i--){
        moves[cnt++]=i;
        char tmp=s[i];
        s[i]=s[i-1];
        s[i-1]=tmp;
    }
    return s;
}

int work(string s, string t){
    int a=0;
    for(int pos=0;pos<n;pos++){
        for(int i=pos;i<n;i++){
            if(t[pos]==s[i]){
                a+=i-pos;
                s= reshape(s,i,pos);
                break;
            }
        }
    }
    return a;
}


void solve() {
    string s, t;
    cin>>n>>s>>t;
    string tt=s, tp=t;
    sort(all(tt));
    sort(all(tp));

    if(tt!=tp){
        cout<<"-1"<<endl;
        return;
    }

    int a= work(s,t);

    if(a==0){
        cout<<"0"<<endl;
        return;
    }

    if(cnt>10000){
        cout<<"-1"<<endl;
        return;

    }

    cout<<a<<endl;

    cout<<moves[0];
    for(int i=1;i<cnt;i++)
        cout<<" "<<moves[i];
    puts("");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}