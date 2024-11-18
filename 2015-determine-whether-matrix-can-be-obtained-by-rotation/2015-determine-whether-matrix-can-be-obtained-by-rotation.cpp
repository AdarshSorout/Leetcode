class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (same(mat, target)) {
                return true;
            }
            mat = rotate(mat);
        }
        return false;
    }

private:
    bool same(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size(), m = mat[0].size();
        if (n == target.size() && m == target[0].size()) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] != target[i][j]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    vector<vector<int>> rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> b(m, vector<int>(n)); // Initialize a new matrix with dimensions m x n
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[j][n - i - 1] = mat[i][j]; // Rotate by 90 degrees
            }
        }
        return b;
    }
};
