class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans; // Store negative numbers
        int count = 0; // Count of negative numbers
        int a = INT_MAX; // Minimum absolute value (not maximum element)

        // First pass: process negatives and track minimum absolute value
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < 0) {
                    ans.push_back(matrix[i][j]);
                    count++;
                }
                a = min(a, abs(matrix[i][j])); // Find the smallest absolute value
            }
        }

        // If the number of negatives is odd, flip the smallest absolute value
        if (count % 2 != 0) {
            bool flipped = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!flipped && abs(matrix[i][j]) == a) {
                        matrix[i][j] = -abs(matrix[i][j]); // Flip the smallest absolute value
                        flipped = true;
                    } else if (matrix[i][j] < 0) {
                        matrix[i][j] = -matrix[i][j]; // Make negatives positive
                    }
                }
            }
        } else {
            // If even negatives, just make all negatives positive
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] < 0) {
                        matrix[i][j] = -matrix[i][j];
                    }
                }
            }
        }

        // Calculate the final sum
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += matrix[i][j];
            }
        }

        return sum;
    }
};
