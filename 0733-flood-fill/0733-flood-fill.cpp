class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void flood(vector<vector<int>>& image, int sr, int sc, int temp, int color) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != temp) {
            return;
        }
        image[sr][sc] = color;
        for (auto& dir : directions) {
            flood(image, sr + dir[0], sc + dir[1], temp, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }
        int temp = image[sr][sc];
        flood(image, sr, sc, temp, color);
        return image;
    }
};
