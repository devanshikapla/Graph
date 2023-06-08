//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indegree[V] = {0};
	    for(int i = 0 ; i < V ; i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue < int > q;
	    for(int i = 0 ; i < V ; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    vector < int > temp;
	    while(!q.empty()){
	        int top = q.front();
	        q.pop();
	        temp.push_back(top);
	        for(auto it : adj[top]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    return temp;
	}
