/*
    Given a list of points on a 2D plane, rearrange these points in any way
    such that in the final permutation of points, the sum of distances of the
    adjacent elements is minimized.
    Constraints: [N <= 15], [-1e9 <= Xi, Yi <=1e9]
    Points : [{0, 0}, {5, 6}, {1, 2}]
    Best permutation -> [{0, 0}, {1, 2}, {5, 6}]]
    Ans = Dist(P1, P3) + Dist(P3, P2)
*/

//solution pending:->


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
    
}

int main(){
    ios_base::sync_with_stdio(false);ff
    cin.tie(0); cout.tie(0);
    solve();

    return 0;
}