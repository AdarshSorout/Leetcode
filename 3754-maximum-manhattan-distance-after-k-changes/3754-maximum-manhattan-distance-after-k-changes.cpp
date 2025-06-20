class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int n = s.size();

        char horDir[2] = {'E', 'W'};
        char verDir[2] = {'N', 'S'};

        for (int h = 0; h < 2; h++) {
            for (int v = 0; v < 2; v++) {
                char hor = horDir[h];
                char ver = verDir[v];

                int remainingK = k;
                int netX = 0, netY = 0;

                for (int i = 0; i < n; i++) {
                    char ch = s[i];

                    if (ch == hor && remainingK > 0) {
                        if (ch == 'W') {
                            ch = 'E';
                        } else {
                            ch = 'W';
                        }
                        remainingK--;
                    } else if (ch == ver && remainingK > 0) {
                        if (ch == 'N') {
                            ch = 'S';
                        } else {
                            ch = 'N';
                        }
                        remainingK--;
                    }

                    if (ch == 'E') netX++;
                    if (ch == 'W') netX--;
                    if (ch == 'N') netY++;
                    if (ch == 'S') netY--;

                    int dist = abs(netX) + abs(netY);
                    if (dist > ans) {
                        ans = dist;
                    }
                }
            }
        }

        return ans;
    }
};
