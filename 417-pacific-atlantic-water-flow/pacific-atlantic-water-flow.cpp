#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false));
        queue<pair<int,int>> q;

        // Directions
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        // Multi-source BFS for Pacific: top row + left col
        for (int j=0; j<n; ++j) { pac[0][j] = true; q.emplace(0,j); }
        for (int i=1; i<m; ++i) { pac[i][0] = true; q.emplace(i,0); }
        bfs(heights, q, pac, dirs, m, n);

        // Multi-source BFS for Atlantic: bottom row + right col
        for (int j=0; j<n; ++j) { atl[m-1][j] = true; q.emplace(m-1,j); }
        for (int i=0; i<m-1; ++i) { atl[i][n-1] = true; q.emplace(i,n-1); }
        bfs(heights, q, atl, dirs, m, n);

        // Collect cells reachable by both
        vector<vector<int>> res;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (pac[i][j] && atl[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }

private:
    void bfs(const vector<vector<int>>& heights, queue<pair<int,int>>& q,
             vector<vector<bool>>& vis, int dirs[4][2], int m, int n) {
        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for (int k=0; k<4; ++k) {
                int nr = r + dirs[k][0];
                int nc = c + dirs[k][1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (vis[nr][nc]) continue;
                // We can move from neighbor to current if neighbor height >= current height
                if (heights[nr][nc] >= heights[r][c]) {
                    vis[nr][nc] = true;
                    q.emplace(nr,nc);
                }
            }
        }
    }
};
