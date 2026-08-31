def topKFrequent(nums: list[int], k: int) -> list[int]:
    freq = {}

    for i in range(len(nums)):
        freq[nums[i]] = freq.get(nums[i], 0) + 1

    return [
        item[0]
        for item in sorted(freq.items(), key=lambda item: item[1], reverse=True)[:k]
    ]


print(topKFrequent([1, 1, 1, 2, 2, 3], k=3))
