int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code 
        priority_queue<pair<int,int> , 
             vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector < int > vis(V , 0);
        pq.push({0 , 0});
        int sum = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top.second;
            int wt = top.first;
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum = sum + wt;
            for(auto it:adj[node]){
                int adjnode=it[0];
                int edw=it[1];
                if(!vis[adjnode]) pq.push({edw , adjnode});
            }
        }
        return sum;
    }
