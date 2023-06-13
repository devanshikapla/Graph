int timer = 0;
    void dfs(int node , int parent , vector < int > & tin , vector < int > & low ,
          vector < int > & vis , vector < int > adj[] , int  & ans , int c , int d){
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent){
                continue;
            }
            if(vis[it] == 0){
                dfs(it ,node,tin,low,vis,adj,ans,c,d);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]&&((it == c && node == d)||(it == d && node == c))){
                    ans = 1;
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector < int > vis(V , 0);
        vector < int > low(V , 0);
        vector < int > tin(V , 0);
        int ans = 0;
        for(int i = 0 ; i < V ; i++){
            if(vis[i] == 0){
                dfs(i , -1 , tin , low , vis , adj , ans , c , d);
            }
        }
        return ans;
        
    }
