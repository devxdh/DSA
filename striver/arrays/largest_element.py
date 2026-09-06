def largestElement(nums):
    maxVal = 0

    for n in nums:
        maxVal = max(maxVal, n)

    return maxVal


print(largestElement([3, 3, 6, 1]))
