// https://cses.fi/problemset/task/1624
 
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
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;
using vec = vector<int>;
 
// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;
 
// Solve
 
//   1 2 3 4 5 6 7 8
// 1 . . . . . . . .
// 2 . . . . . . . .
// 3 . . . . . . . .
// 4 . . . . . . . .
// 5 . . . . . . . .
// 6 . . . . . . . .
// 7 . . . . . . . .
// 8 . . . . . . . .
 
void solve() {
    bool board[9][9];
    bool row[9];
    bool downright[15];
    bool upright[15];
    int ans = 0;
    memset(board, 0, sizeof(board));
    memset(row, 0, sizeof(row));
    memset(downright, 0, sizeof(downright));
    memset(upright, 0, sizeof(upright));
    for(int i =1; i<=8; i++){
        row[i] = false;
        for(int j = 1; j<=8; j++){
            char c; cin>>c;
            if(c=='*')  board[i][j]=true;
            else    board[i][j]=false;
        }
    }
    function<void(int)> solve1 = [&](int x) -> void{
        if(x==9){
            ans++;
            return;
        }
        for(int i =1; i<=8; i++){
            if(!board[i][x]&&!row[i]){
                if(!downright[x-i+7]&&!upright[x+i-2]){
                    row[i] = downright[x-i+7] = upright[x+i-2] = true;
                    solve1(x+1); 
                    row[i] = downright[x-i+7] = upright[x+i-2] = false;
                }
            }
        }
    };
    solve1(1);
    cout<<ans<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
 
    return 0;
}