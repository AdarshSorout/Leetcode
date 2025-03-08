class Solution {
public:
   int reverse(int x) {
    long long res = 0;

    while (x != 0) {
        int rem = x % 10;
        res = res * 10 + rem;

        
        if (res > INT_MAX || res < INT_MIN) return 0;

        x /= 10;
    }

    return static_cast<int>(res);
}

};