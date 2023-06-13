#include <bits/stdc++.h>
void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&s){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it , adj , vis ,s );
        }
    }
    s.push(node);
}

void dfs2(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans){
    vis[node] = 1;
    ans.push_back(node);
    for(auto i: adj[node]) {
        if(!vis[i])dfs2(i,adj,vis,ans);
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector < int > adj[n];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
    }
    vector < int > vis(n);
    stack < int > st;
    for(int i = 0 ; i < n; i++){
        if(!vis[i]){
            dfs(i , adj , vis , st);
        }
    }
    vector < int > adj2[n];
    for(int i = 0 ; i < n ; i++){
        vis[i] = 0;
        for(auto it : adj[i]){
            adj2[it].push_back(i);
        }
    }
    vector < vector < int >> res;
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        vector < int > ans;
        if(!vis[it]){
            dfs2(it , adj2 , vis , ans);
        }
        res.push_back(ans);
    }
    return res;

}
