def containsDuplicate(nums: list[int]) -> bool:
    return len(set(nums)) != len(nums)

print(containsDuplicate([1,2,3,1]))