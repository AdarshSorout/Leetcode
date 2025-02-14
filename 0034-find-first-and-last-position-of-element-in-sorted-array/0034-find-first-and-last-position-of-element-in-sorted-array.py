from typing import List

class Solution:
    def findRightMost(self, nums: List[int], target: int, n: int) -> int:
        l, r = 0, n - 1
        right_most = -1 

        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                right_most = mid  
                l = mid + 1
            elif nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1

        return right_most 

    def findLeftMost(self, nums: List[int], target: int, n: int) -> int:
        l, r = 0, n - 1
        left_most = -1  

        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                left_most = mid  
                r = mid - 1
            elif nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1

        return left_most  

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)  
        left_most = self.findLeftMost(nums, target, n)
        right_most = self.findRightMost(nums, target, n)
        return [left_most, right_most]
