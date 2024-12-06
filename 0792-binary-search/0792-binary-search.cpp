class Solution {
public:

int bSearch(vector<int>& nums, int low, int high, int x)
{
	if(low > high)
		return -1;
	int mid = low+ (high-low)/2;
	if(nums[mid] == x)
		return mid;
	else if(nums[mid] > x)
		return bSearch(nums, low, mid - 1, x);

	else
		return bSearch(nums, mid + 1, high, x);
}
    int search(vector<int>& nums, int target) {
        int low =0;
        int high =nums.size()-1;
return bSearch(nums,low,high,target);
    }
};