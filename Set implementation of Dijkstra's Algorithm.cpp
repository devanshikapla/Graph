vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        //declaration of set
        set < pair < int , int >> st;
        //distance array with all values intitalized to 1e9
        vector < int > dist(V , 1e9);
        
        //inserting source node
        st.insert({0 , S});
        //setting distance of source node to 0;
        dist[S] = 0;
        
        // Now, erase the minimum distance node first from the set
        // and traverse for all its adjacent nodes.
        while(!st.empty()){
            auto it = *(st.begin());
            int top = it.second;
            int dis = it.first;
            st.erase(it);
            
            //Check for neighbour nodes
            
            for(auto it : adj[top]){
                int adjNode = it[0];
                int edgW = it[1];
                if(dis + edgW < dist[adjNode]){
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode] , adjNode});
                    }
                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode] , adjNode});
                }
            }
        }
        return dist;
    }
