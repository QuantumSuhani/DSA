class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> height(n, 0);
        int result = 0;

        for (int i = 0; i < m; i++) {
            // Update histogram heights
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j]++;
            }

            // Count submatrices ending at row i
            for (int j = 0; j < n; j++) {
                int minHeight = height[j];
                for (int k = j; k >= 0 && minHeight > 0; k--) {
                    minHeight = min(minHeight, height[k]);
                    result += minHeight;
                }
            }
        }
        return result;
    }
};
