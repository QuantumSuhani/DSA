#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Min-heap storing {height, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int ans = 0;
        
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int height = top[0];
            int r = top[1];
            int c = top[2];
            
            ans = max(ans, height);
            if(r == n-1 && c == n-1)
                return ans;
            
            for(auto &d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }
        return ans;
    }
};
