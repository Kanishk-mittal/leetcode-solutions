class Solution(object):
    def digitSum(self, num):
        result=0
        while num>0:
            result+=num%10
            num//=10
        return result

    def minSwaps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sorted_nums=sorted(nums,key= lambda x:(self.digitSum(x),x))
        # we need a map to index in the original array as well
        mp={}
        for i in range(len(nums)):
            mp[nums[i]]=i
        # for each value in the sorted array if it is same as the original array we continue else we swap
        result=0
        for i in range(len(nums)):
            if nums[i]==sorted_nums[i]:
                continue
            result+=1
            correct_idx=mp[sorted_nums[i]]
            # now we will put the value at correct_idx at i and i at correct_idx
            mp[nums[i]]=correct_idx
            mp[nums[correct_idx]]=i
            nums[correct_idx]=nums[i]
            nums[i]=sorted_nums[i]
        return result

sol=Solution()
print(sol.minSwaps([22,14,33,7]))