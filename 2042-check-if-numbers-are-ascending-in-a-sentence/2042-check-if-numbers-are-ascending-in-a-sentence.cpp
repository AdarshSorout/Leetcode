class Solution {
public:
    bool isDigit(char c) {
        for (int i = 0; i < 10; i++) {
            if (c == '0' + i) {
                return true;
            }
        }
        return false;
    }

    bool areNumbersAscending(string s) {
        int n = s.size();
        int res = -1;  

        for (int i = 0; i < n; i++) {
            if (isDigit(s[i])) {
                int ans = 0; 

                while (i < n && isDigit(s[i])) {
                    ans = ans * 10 + (s[i] - '0');
                    i++;
                }

                if (ans <= res) {
                    return false;
                }
                res = ans;
            }
        }
        return true;
    }
};
