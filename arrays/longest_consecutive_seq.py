def longestConsecutive(nums: list[int]) -> int:
    mseq = 0
    numsSet = set(nums)

    for n in nums:
        length = 0
        if (n - 1) not in numsSet:
            while (n + length) in numsSet:
                length += 1
            mseq = max(mseq, length)
    return mseq


print(longestConsecutive([100, 4, 200, 1, 3, 2]))
