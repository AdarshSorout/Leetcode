class Solution {
public:
    long long countLessEqual(const vector<int>& nums1, const vector<int>& nums2, long long x) {
        long long count = 0;
        int m = nums2.size();

        for (int i = 0; i < nums1.size(); i++) {
            int left = 0, right = m - 1;

            if (nums1[i] >= 0) {
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (1LL * nums1[i] * nums2[mid] <= x)
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
                count += left;
            } else {
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (1LL * nums1[i] * nums2[mid] <= x)
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
                count += (m - left);
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long low = -1e10, high = 1e10;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (countLessEqual(nums1, nums2, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
