#include <bits/stdc++.h>
using namespace std;

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
    queue<int> qu;
    visited[source]=true;
    qu.push(source);
    while(!qu.empty()){
        int top = qu.front();
        qu.pop();
        cout<<top<<" ";
        for(auto neighbour:edges(top)){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                qu.push(neighbour);
            }
        }
    }
}