
class Solution {
  private:
  void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>>& v, int row, int col) {
      vis[i][j] = 1;
      v.push_back({i-row,j-col});
      int drow[] = {-1,0,1,0};
      int dcol[] = {0,1,0,-1};
      for(int k=0;k<4;k++){
          int nrow = i + drow[k];
          int ncol = j + dcol[k];
          if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol]){
              dfs(nrow,ncol,grid,vis,v,row,col);
          }
      }
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>>s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> v;
                    dfs(i,j,grid,vis,v,i,j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};
