class Solution {
public:
    
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<vector<int>> q; //{x, y, steps, current_key_status_decimal}
        int count = 0;
        for(int i = 0; i<m; i++) {
            
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == '@') {
                    q.push({i, j, 0, 0});
                } else if(grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    count++;
                }
                
            }
            
        }
        
        /*
            If we have 3 keys - '111'  - Decimal value = 8 = 2^3 - 1
            If we have 4 keys - '1111' - Decimal value = 15 = 2^4 - 1
        */
        
        int final = pow(2, count) - 1;
        
        
        int visited[m][n][final +1];
        memset(visited, 0, sizeof(visited));
        
        while(!q.empty()) {
            
            auto temp = q.front();
            q.pop();
            
            int i                            = temp[0];
            int j                            = temp[1];
            int steps                        = temp[2];
            int current_key   = temp[3];
            
            if(current_key == final) {
                return steps;
            }
            
            for(vector<int> & dir : directions) {
                
                int dr = i + dir[0];
                int dc = j + dir[1];
                
                if(dr >= 0 && dr < m && dc >= 0 && dc < n && grid[dr][dc] != '#') {
                    char ch = grid[dr][dc];
                        
                    if(grid[dr][dc] >= 'A' && grid[dr][dc] <= 'F') { //Lock
                        
                        if(visited[dr][dc][current_key] == 0 && 
                          ((current_key >> (ch-'A')) & 1) == 1) { //Already have that key then we unlock
                            visited[dr][dc][current_key] = 1;
                            q.push({dr, dc, steps+1, current_key});
                        }
                        
                    } else if(grid[dr][dc] >= 'a' && grid[dr][dc] <= 'f') { //Key
                        
                        int newKey = current_key | (1 << (ch - 'a'));
                        
                        if(visited[dr][dc][newKey] == 0) {
                            visited[dr][dc][newKey] = 1;
                            q.push({dr, dc, steps+1, newKey});
                        }
                        
                    } else {
                        if(visited[dr][dc][current_key] == 0) {
                            visited[dr][dc][current_key] = 1;
                            q.push({dr, dc, steps+1, current_key});
                        }
                    }
                    
                }
                
            }
            
        }
        
        return -1;
    }
};
