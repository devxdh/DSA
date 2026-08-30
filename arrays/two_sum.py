def twoSum(nums: list[int], target: int) -> list[int]:
    seen = {}
    res = []

    for i in range(len(nums)):
        diff = target - nums[i]

        if diff in seen:
            res = [seen[diff], i]

        seen[nums[i]] = i

    return res


print(twoSum([2, 7, 11, 15], 9))
