class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map={}

        for i,num in enumerate(nums):
            num_map[num]=i

        for i,num in enumerate(nums):
             complement=target-num
             if complement in num_map and num_map[complement] !=i:
                 return [i,num_map[complement]]

        return []   