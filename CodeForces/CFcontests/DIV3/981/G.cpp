// https://codeforces.com/contest/2033/problem/G

#include <bits/stdc++.h>
using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// Macros
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define up(v) upper_bound(v)
#define low(v) lower_bound(v)

// Read and Print
#define read(a, n) for (int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for (int i = 0; i < n; ++i) { cout << a[i] << " "; } cout << "\n";
#define endl "\n"
#define sp " "

// Typedefs
typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> plli;
typedef pair<int, int> pii;
typedef vector<lli> vi;
typedef vector<vector<lli>> vvi;
using vec = vector<int>;
#define int long long

// Constants
const int mod = 1e9 + 7;

struct segtree{
    struct node{
        int x = 0;
 
        void apply(int l, int r, int y){
            x = y;
        }
    };
 
    int n;
    vector <node> seg;
 
    node unite(node a, node b){
        node res;
        res.x = max(a.x, b.x);
        return res;
    }
 
    void push(int l, int r, int pos){
        
    }
 
    void pull(int pos){
        seg[pos] = unite(seg[pos * 2], seg[pos * 2 + 1]);
    }
 
    void build(int l, int r, int pos){
        if (l == r){
            return;
        }
 
        int mid = (l + r) / 2;
        build(l, mid, pos * 2);
        build(mid + 1, r, pos * 2 + 1);
        pull(pos);
    }
 
    template<typename M>
    void build(int l, int r, int pos, vector<M> &v){
        if (l == r){
            seg[pos].apply(l, r, v[l]);
            return;
        }
 
        int mid = (l + r) / 2;
        build(l, mid, pos * 2, v);
        build(mid + 1, r, pos * 2 + 1, v);
        pull(pos);
    }
 
    node query(int l, int r, int pos, int ql, int qr){
        push(l, r, pos);
        if (l >= ql && r <= qr){
            return seg[pos];
        }
        
        int mid = (l + r) / 2;
        node res{};
        if (qr <= mid) res = query(l, mid, pos * 2, ql, qr);
        else if (ql > mid) res = query(mid + 1, r, pos * 2 + 1, ql, qr);
        else res = unite(query(l, mid, pos * 2, ql, qr), query(mid + 1, r, pos * 2 + 1, ql, qr));
        
        pull(pos);
        return res;
    }
 
    template <typename... M>
    void modify(int l, int r, int pos, int ql, int qr, M&... v){
        push(l, r, pos);
        if (l >= ql && r <= qr){
            seg[pos].apply(l, r, v...);
            return;
        }
 
        int mid = (l + r) / 2;
        if (ql <= mid) modify(l, mid, pos * 2, ql, qr, v...);
        if (qr > mid) modify(mid + 1, r, pos * 2 + 1, ql, qr, v...);
 
        pull(pos);
    }
 
    segtree (int _n){
        n = _n;
        seg.resize(4 * n + 1);
        build(1, n, 1);
    }
 
    template <typename M>
    segtree (int _n, vector<M> &v){
        n = _n;
        seg.resize(4 * n + 1);
        if (v.size() == n){
            v.insert(v.begin(), M());
        }
        build(1, n, 1, v);
    }
 
    node query(int l, int r){
        return query(1, n, 1, l, r);
    }
 
    node query(int x){
        return query(1, n, 1, x, x);
    }
 
    template <typename... M>
    void modify(int ql, int qr, M&...v){
        modify(1, n, 1, ql, qr, v...);
    }
};
 
 
void solve() {
    int n; cin >> n;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<pair<int, int>>> b(n + 1);
    vector <int> deep(n + 1, 0);
    
    auto dfs = [&](auto self, int u, int par) -> void{
        deep[u] = 0;
        for (int v : adj[u]){
            if (v != par){
                self(self, v, u);
                deep[u] = max(deep[u], deep[v] + 1);
                
                b[u].push_back({deep[v] + 1, v});
            }
        }  
        
        sort(b[u].begin(), b[u].end());
        reverse(b[u].begin(), b[u].end());
        
        vector <pair<int, int>> c;
        for (int i = 0; i < min(2LL, (int)b[u].size()); i++){
            c.push_back(b[u][i]);
        }
        
        b[u] = c;
    };
    
    dfs(dfs, 1, -1);
    
    int t = 0;
    int q; cin >> q;
    
    vector <vector<pair<int, int>>> d(n + 1);
    vector <int> ans(q);
    for (int i = 0; i < q; i++){
        int v, k; cin >> v >> k;
        
        d[v].push_back({k, i});
    }
    
    segtree seg2(n);
    
    auto dfs2 = [&](auto self, int u, int par) -> void {
        for (auto [k, i] : d[u]){
            ans[i] = deep[u];
            
            if (t){
                int r = t;
                int l = t - k + 1;
                l = max(l, 1LL);
                if (l <= r){
                    ans[i] = max(ans[i], seg2.query(l, r).x + t + 1);
                }
            }
        }
        
        for (int v : adj[u]) if (v != par){
            int got = 0;
            for (auto [e, f] : b[u]){
                if (f != v){
                    got = max(got, e);
                }
            }
            
            t += 1;
            got -= t;
            seg2.modify(t, t, got);
            
            self(self, v, u);
            t -= 1;
        }
    };
    
    dfs2(dfs2, 1, -1);
    
    for (auto x : ans){
        cout << x << " ";
    }
    cout << "\n";
}
 
int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    
    cin >> t;
    while(t--)  solve();
    return 0;
}