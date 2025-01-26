// https://cses.fi/problemset/task/2162

#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
#define up          upper_bound
#define low         lower_bound

// Read and Print
#define read(a, n)  for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) { cout << a[i] << " "; } cout << "\n";
#define endl        "\n"
#define sp          " "

// Typedefs
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector <ll> vi;
using vec = vector<int>;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e18 + 6;

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

        if (d > dist[node]) continue;

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

    SegmentTree(int size) : n(size) {
        tree.resize(4 * n, 0);
    }

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
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        ll left_sum = query(2 * node, start, mid, l, r);
        ll right_sum = query(2 * node + 1, mid + 1, end, l, r);
        return left_sum + right_sum;
    }

    void update(int idx, ll val) {
        update(1, 0, n - 1, idx, val);
    }

    ll query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

// GCD function
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

// LCM function
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

// Factors function
vector<ll> factors(ll n) {
    vector<ll> result;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            result.pb(i);
            if (i != n / i) result.pb(n / i);
        }
    }
    sort(all(result));
    return result;
}

// Sparse Table for Range Minimum Query (RMQ)
struct SparseTable {
    int n, maxLog;
    vector<vector<int>> table;

    SparseTable(const vector<int>& arr) {
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

// Solve
void solve() {
    int n;
    cin>>n;
    vec a(n);
    iota(all(a), 1);
    while(a.size()>1){
        vec b;
        for(int i = 0; i<a.size(); i++){
            if(i%2 == 1)    cout<<a[i]<<sp;
            else    b.pb(a[i]);
        }
        if(a.size()%2 == 0) a = b;
        else{
            int x = b.back();
            b.pop_back();
            a.clear();
            a.pb(x);
            for(auto it:b)
                a.pb(it);
        }
    }
    cout<<a[0]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
