class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //This question is a straightforward example of bellmond ford algorithm
        // We have to basically check for n - 1 nodes and we have to relax n - 1 edges
        // Creating the distance array.
        vector < int > dist(n + 1 , 1e9);
        //As k is the source node so distance of k, should be updated to 0
        dist[k] = 0;
        //Relaxing n - 1 edges

       for(int i = 0; i < n - 1 ; i++){
            for(auto it : times)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
            }
        }
        //Printing the ans;
        int ans = 0;
        for(int i = 1; i <= n ; i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans , dist[i]);
        }
        return ans;
    }
};
