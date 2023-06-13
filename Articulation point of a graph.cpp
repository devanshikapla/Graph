  int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[],
             vector<int> &mark, vector<int>adj[]){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node] , low[it]);
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
        //for starting nodes;
        if(child > 1 && parent == -1){
            mark[node] = 1;
        }
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        //vis array used to keep track of visited nodes
        vector < int > vis(n , 0 );
        //time of insertion array
        int tin[n];
        //lowest time of insertion array
        int low[n];
        //used to mark the articulation point;
        vector < int > mark(n , 0);
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(i , -1 , vis , tin , low , mark , adj);
            }
        }
        
        vector < int > ans;
        //pushing marked nodes from the mark[i] into ans vector
        for(int i = 0 ; i < n ; i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
