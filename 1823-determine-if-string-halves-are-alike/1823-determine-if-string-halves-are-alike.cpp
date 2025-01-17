class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowels = "aeiouAEIOU";
        int a = 0, b = 0;
        int n = s.size();
        
        for (int i = 0; i < n / 2; i++) {
            if (vowels.find(s[i]) != string::npos) {
                a++;
            }
        }
        for (int i = n / 2; i < n; i++) {
            if (vowels.find(s[i]) != string::npos) {
                b++;
            }
        }
        
        return a == b;
    }
};
