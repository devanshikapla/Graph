#include <bits/stdc++.h> 
void dfs(vector < vector < int >> & adj , vector < bool > & visited , 
            stack < int > & st , int node){
    if(visited[node]) return;
    visited[node] = true;
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(adj , visited , st ,it);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    //making adjancy list of the matrix;
    vector < vector < int >> adj(v);
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);

    }
    //visited array
    vector < bool > visited(v , false);
    stack < int > st;
    for(int i = 0 ; i < v ; i++){
        if(!visited[i]){
            dfs(adj , visited , st , i);
        }
    }
    vector < int > ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
