from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k=0
        list1=[]
        for i in range(len(nums)):
            if nums[i]==val:
                list1.append(nums[i])
            else:
                k+=1
        for j in list1:
            nums.remove(j)
        return
        