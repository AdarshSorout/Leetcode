class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int area(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
            return 0;
        }

        grid[i][j] = -1;  
        int localSum = 1;

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            localSum += area(grid, new_i, new_j);  
        }

        return localSum;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxSum = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxSum = max(maxSum, area(grid, i, j));
                }
            }
        }

        return maxSum;
    }
};
