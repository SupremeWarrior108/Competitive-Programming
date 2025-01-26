// https://codeforces.com/problemset/problem/744/A

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

// Macros 
#define pb            push_back
#define pf            push_front
#define mp            make_pair
#define ff            first
#define ss            second
#define all(v)        v.begin(), v.end()
#define rall(v)       v.rbegin(), v.rend()
#define up            upper_bound
#define low           lower_bound
#define read(a, n)    for (ll i = 0; i < n; ++i)  cin >> a[i];
#define print(a, n)   for (ll i = 0; i < n; ++i) {  cout << a[i] << " ";    } cout << "\n";
#define endl          "\n"
#define sp            " "
#define v             vector
#define debug(x)      cout << #x << "=" << x << endl;
#define fo(i, x, n, a) for (ll i = x; a > 0 ? i < n : i > n; i += a)
#define len(mask)     (__builtin_popcountll(mask))

// Typedefs
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
typedef v<vi> vvi;
using vec = vector<int>;

// POLICY BASED DATASTRUCTURES
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e18 + 6;

// Function declarations
void bfs(ll start, const vector<vi> &adj, vi &dist);
void dfs(ll node, const vector<vi> &adj, vector<bool> &visited);
void dijkstra(ll start, const vector<vector<pll>> &adj, vector<ll> &dist);
int gcd(int a, int b);
int lcm(int a, int b);
int mod_add(int a, int b, int m = mod);
int mod_sub(int a, int b, int m = mod);
int mod_mul(int a, int b, int m = mod);
int mod_pow(int a, int b, int m = mod);
vector<ll> factors(ll n);

// Solve

vi root;
ll find(ll p) {
    if (p != root[p]) {
        root[p] = find(root[p]);
    }
    return root[p];
}

ll c2(ll n) {
    return n * (n - 1) / 2;
}

// Solve

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vi special(k);
    read(special, k); 
    root.resize(n + 1);
    iota(all(root), 0);
    fo(i, 0, m, 1) {
        ll u, v;
        cin >> u >> v;
        u = find(u);
        v = find(v);
        root[v] = u;
    }
    vi sz(n + 1, 0);
    fo(i, 1, n + 1, 1) {
        sz[find(i)]++;
    }
    ll leftover = n, ans = 0, largest = 0;
    for (auto x : special) {
        ll d = find(x);
        largest = max(largest, sz[d]);
        ans += c2(sz[d]);
        leftover -= sz[d];
    }
    ans -= c2(largest);              
    ans += c2(largest + leftover);   
    ans -= m;                        
    cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t --> 0) {
    solve();
  }
  return 0;
}

// BFS
void bfs(ll start, const vector<vi> &adj, vi &dist) {
  queue<ll> q;
  q.push(start);
  dist[start] = 0;

  while (!q.empty()) {
    ll node = q.front();
    q.pop();
    for (ll neighbor : adj[node]) {
      if (dist[neighbor] == INF) {
        dist[neighbor] = dist[node] + 1;
        q.push(neighbor);
      }
    }
  }
}

// DFS
void dfs(ll node, const vector<vi> &adj, vector<bool> &visited) {
  visited[node] = true;
  for (ll neighbor : adj[node]) {
    if (!visited[neighbor]) {
      dfs(neighbor, adj, visited);
    }
  }
}

// Dijkstra's Algorithm
void dijkstra(ll start, const vector<vector<pll>> &adj, vector<ll> &dist) {
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    auto [d, node] = pq.top();
    pq.pop();

    if (d > dist[node])
      continue;

    for (auto [weight, neighbor] : adj[node]) {
      if (dist[node] + weight < dist[neighbor]) {
        dist[neighbor] = dist[node] + weight;
        pq.push({dist[neighbor], neighbor});
      }
    }
  }
}

// Segment Tree
struct SegmentTree {
  int n;
  vector<ll> tree;

  SegmentTree(int size) : n(size) { tree.resize(4 * n, 0); }

  void build(const vector<ll> &arr, int node, int start, int end) {
    if (start == end) {
      tree[node] = arr[start];
    } else {
      int mid = (start + end) / 2;
      build(arr, 2 * node, start, mid);
      build(arr, 2 * node + 1, mid + 1, end);
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }

  void update(int node, int start, int end, int idx, ll val) {
    if (start == end) {
      tree[node] = val;
    } else {
      int mid = (start + end) / 2;
      if (start <= idx && idx <= mid) {
        update(2 * node, start, mid, idx, val);
      } else {
        update(2 * node + 1, mid + 1, end, idx, val);
      }
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }

  ll query(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
      return 0;
    if (l <= start && end <= r)
      return tree[node];
    int mid = (start + end) / 2;
    ll left_sum = query(2 * node, start, mid, l, r);
    ll right_sum = query(2 * node + 1, mid + 1, end, l, r);
    return left_sum + right_sum;
  }

  void update(int idx, ll val) { update(1, 0, n - 1, idx, val); }

  ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int mod_add(int a, int b, int m) { return (a % m + b % m) % m; }
int mod_sub(int a, int b, int m) { return (a % m - b % m + m) % m; }
int mod_mul(int a, int b, int m) { return (a % m * b % m) % m; }
int mod_pow(int a, int b, int m) {
  int res = 1;
  while (b > 0) {
    if (b & 1)
      res = mod_mul(res, a, m);
    a = mod_mul(a, a, m);
    b >>= 1;
  }
  return res;
}
vector<ll> factors(ll n) {
  vector<ll> result;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      result.pb(i);
      if (i != n / i)
        result.pb(n / i);
    }
  }
  sort(all(result));
  return result;
}

// Sparse Table for Range Minimum Query (RMQ)
struct SparseTable {
  int n, maxLog;
  vector<vector<int>> table;

  SparseTable(const vector<int> &arr) {
    n = arr.size();
    maxLog = log2(n) + 1;
    table.assign(n, vector<int>(maxLog));

    // Initialize table with the input array for the 0th power of 2
    for (int i = 0; i < n; i++) {
      table[i][0] = arr[i];
    }

    // Build the table
    for (int j = 1; j < maxLog; j++) {
      for (int i = 0; i + (1 << j) <= n; i++) {
        table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  // Query for the minimum in range [L, R]
  int query(int L, int R) {
    int j = log2(R - L + 1);
    return min(table[L][j], table[R - (1 << j) + 1][j]);
  }
};
