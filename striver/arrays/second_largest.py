def secondLargestElement(nums) -> int:
    maxV = float("-inf")
    secMaxV = float("-inf")

    for i in range(len(nums)):
        if nums[i] > maxV:
            secMaxV = maxV
            maxV = nums[i]
        elif nums[i] < maxV and nums[i] > secMaxV:
            secMaxV = nums[i]

    if secMaxV == float("-inf"):
        return -1

    return secMaxV


print(secondLargestElement([8, 8, 7, 6, 5]))
