// https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

// Macros
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define up upper_bound
#define low lower_bound
#define read(a, n)                                                             \
  for (ll i = 0; i < n; ++i)                                                   \
    cin >> a[i];
#define print(a, n)                                                            \
  for (ll i = 0; i < n; ++i) {                                                 \
    cout << a[i] << " ";                                                       \
  }                                                                            \
  cout << "\n";
#define endl "\n"
#define sp " "
#define debug(x) cout << #x << "=" << x << endl;

// Typedefs
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
using vec = vector<int>;

// POLICY BASED DATASTRUCTURES
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e18 + 6;

// functions
bool bfs(ll start, ll end, const vvi &adj, vi &dist, vi &traversal, vector<bool> vis);

// Solve

void solve() {
    int n, m;
    cin>>n>>m;
    vvi ar(1e5+1);
    vi dist(1e5+1), traversal(1e5+1);
    vector<bool> vis(1e5+1);
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        ar[a].pb(b);
        ar[b].pb(a);
    }
    if(bfs(1, n, ar, dist, traversal, vis)){
        cout<<dist[n]<<endl;
        int path = n;
        vec res;
        while(path != 0){
            res.pb(path);
            path = traversal[path];
        }
        reverse(all(res));
        for(auto x:res) cout<<x<<sp;
        cout<<endl;
    }
    else    cout<<"IMPOSSIBLE"<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

// BFS
bool bfs(ll start, ll end, const vector<vi> &adj, vi &dist, vi &traversal, vector<bool> vis) {
    queue<ll> q;
    q.push(start);
    dist[start] = 1;
    vis[start] = 1;
    while (!q.empty()) {
        ll node = q.front();
        q.pop();
        if(end == node) return true;
        traversal.pb(node);
        for (ll neighbor : adj[node]) {
            if (vis[neighbor] == false) {
                dist[neighbor] = dist[node] + 1;
                vis[neighbor] = true;
                traversal[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    return false;
}

// DFS
void dfs(ll node, const vector<vi> &adj, vector<bool> &visited, vi &traversal) {
  visited[node] = true;
  traversal.push_back(node);
  for (ll neighbor : adj[node]) {
    if (!visited[neighbor]) {
      dfs(neighbor, adj, visited, traversal);
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
int mod_add(int a, int b, int m = mod) { return (a % m + b % m) % m; }
int mod_sub(int a, int b, int m = mod) { return (a % m - b % m + m) % m; }
int mod_mul(int a, int b, int m = mod) { return (a % m * b % m) % m; }
int mod_pow(int a, int b, int m = mod) {
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
