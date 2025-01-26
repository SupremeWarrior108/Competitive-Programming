#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long double ld;
typedef unsigned long long ull;
#define MOD 1000000007
#define maxn 100000000000017    
#define nl "\n"
#define cnl cout<<"\n"
#define mk make_pair
#define pi pair<int, int>
#define pll pair<int, int>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define all1(v) v.rbegin(),v.rend()
#define vll vector<int>
#define vld vector<ld>
#define vpll vector<pint>
#define ff first
#define ss second
#define pb push_back
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define bitcnt(n) __builtin_popcount(n)
#define mask(i) (1 << (i))
#define bitmask(n, i) (((n) >> (i)) & 1)
#define set_on(n, i) ((n) | mask(i))
#define set_off(n, i) ((n) & ~mask(i))
#define f1(i, n) for(int i = 1; i <= n; i++)
#define f0(i, n) for(int i = 0; i < n; i++)
#define fe(x, v) for(auto x : v)
#define getunique(v) {sort(aint(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
 
/*---------------------------------------------------------------------------------------------------------------------------*/
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
bool revsort(int a, int b) {return a > b;}
int lcm(int a, int b) {return (a / gcd(a, b)) * b;}
int Mul(int x, int n, int M) {int ans = 0; for(;n; n /= 2, x = (x + x) % M)  if(n & 1) ans = (ans + x) % M; return ans;}
int Pow(int x, int n, int M) {int ans = 1; for(;n; n /= 2, x = Mul(x, x, M)) if(n & 1) ans = Mul(ans, x, M); return ans;}
int Pow(int x, int n) {int ans = 1; for(;n; n /= 2, x = x * x) if(n & 1) ans = ans * x; return ans;}
int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
int phin(int n) {int number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/
 
template <typename T>void read(T &p){cin >> p;} 
template <typename T, typename T1>void read(pair<T, T1> &p){read(p.ff);read(p.ss);}
template <typename T>void read(T arr[], int n){for (int i = 0; i < n; i++){read(arr[i]);}}
template <typename T>void read(vector<T> &arr){for (int i = 0; i < arr.size(); i++){read(arr[i]);}}
template <typename T>void out(T& n){cout << n;}
template <typename T, typename T1>void out(pair<T, T1> &p){cout << "(";out(p.ff);cout << ",";out(p.ss);cout << ")";}
template <typename T>void out(T arr[], int n){for (int i = 0; i < n; i++){out(arr[i]);cout << " ";}}
template <typename T>void out(vector<T> &arr){for (int i = 0; i < arr.size(); i++){out(arr[i]);cout<<" ";}}
template <typename T>void out(set<T> &arr){for (auto i:arr){out(i);cout << " ";}} 
template <typename T> void out(multiset<T> &arr){for (auto i:arr){out(i);cout << " ";}}
template <typename T, typename T1> void out(map<T,T1> &m){ for (auto i:m) {out(i.first);cout<<" -> ";out(i.second);cout<<", ";}}
 
/******************************************************************************************/
 
 
 
void solve(){
     int n;
     cin>>n;
     vi a(n);
     map<int,int>mp;
     read(a);
     sort(all(a));
     int sum=0;
    //  f0(i,n){
    //     sum+=a[i];
    //     mp[sum]++;
    //  }
     int i=1;
     mp[0]=1;
     f1(i,n){
        if(mp[i-1]<a[i-1]){
            cout<<mp[i-1]<<nl;
            return;
        }
        mp[i]=mp[i-1]+a[i-1];
 
     }
     cout<<mp[n]<<nl;
     
    //  while(1){
    //     // if(mp[i]){
    //     //     i++;
    //     //     continue;
    //     // }
    //     for(auto j:mp){
    //         if(mp[j.ff-i] && j.ff-i>=0){
    //             mp[i]++;
    //             break;
    //         }
    //     }
    //     if(!mp[i]){
    //         cout<<i<<nl;
    //         return;
    //     }
    //     i++;
    //  }
    //  auto good=[&](int x)->bool{
    //     if(mp[x])return true;
    //     for(auto j:mp){
    //         if(mp[j.ff-x] && j.ff-x>=0){
    //             mp[x]++;
    //             return true;
    //         }
    //     }
    //     return false;
 
    //  };
    //  while(l<r){
    //     int mid=l+(r-l)/2;
    //     if(good(mid)){
 
    //     }
 
    //  }
 
}
 
int32_t main(){
    fast 
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
 
    
}