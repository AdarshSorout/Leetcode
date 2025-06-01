class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        grid[0][0] = 1;

        int dr[] = {-1, -1, 0, +1, +1, +1, 0, -1};
        int dc[] = {0, +1, +1, +1, 0, -1, -1, -1};

        while (!q.empty()) {
            auto [dist, pos] = q.front();
             q.pop();
            int r = pos.first, c = pos.second;

            if (r == n - 1 && c == n - 1) return dist;

            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0) {
                    q.push({dist + 1, {newr, newc}});
                    grid[newr][newc] = 1;
                }
            }
        }

        return -1;
    }
};
