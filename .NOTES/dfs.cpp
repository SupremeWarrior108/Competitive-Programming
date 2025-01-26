#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, vector<vector<int>> &edges, vector<vector<int>> &traverse, vector<bool> &visited){
    traverse.pb(cur);
    vis[cur]=true;
    for(auto neighbour:edges){
        if(!visited[neighour])
            dfs(neighbour, edges, traverse, visited);
    }
}
void solve(){
    int n, m;   cin>>n>>m;
    vector<vector<int>> edges(n);
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--;    b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    int source = 0;
    vector<int> traverse;
    vector<bool> visited(n, false);
    dfs(source, edges, traverse, visited);
    for(auto x:traverse)
        cout<<x<<" ";
}