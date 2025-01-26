// Find out the size of each connected component in the graph

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
    vector<vector<int>> components;
    int source = 0;
    vector<int> traverse;
    vector<bool> visited(n, false);
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            vector<int> comp;
            dfs(source, edges, comp, visited);
            components.push_back(comp);
        }
    }
    for(auto x:components){
        for(auto y:x)   cout<<y<<" ";
        cout<<endl;
    }
}