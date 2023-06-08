class Solution {
public:
    bool dfs(int start , int col , vector < int > & color , vector < vector < int >> & adj){
        color[start] = col;
        for(auto it : adj[start]){
            if(color[it] == -1){
                if(dfs(it , !col , color , adj) == false) return false;
            }
            else if(color[it] == col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //DFS approach
        int n = graph.size();
        int m = graph[0].size();
       
        
        vector < int > color(n , -1);
        for(int i = 0 ; i < n ; i++){
   
            if(color[i] == -1){
                if(dfs(i , 0 , color , graph) == false){
                    return false;
                }
            }

        }
        return true;

    }
};
