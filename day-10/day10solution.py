class Solution:
    def pivotIndex(self, nums: list[int]) -> int:
        total=0
        leftsum=0
        for number in nums:
            total+=number
        for i in range(len(nums)):
           rightsum=total-leftsum-nums[i]
           if rightsum==leftsum:
              return i
           leftsum+=nums[i] 
        return -1    
