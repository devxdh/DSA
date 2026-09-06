def groupAnagrams(strs: list[str]) -> list[list[str]]:
    res = {}

    for i in range(len(strs)):
        sortedStr = "".join(sorted(strs[i]))
        if sortedStr not in res:
            res[sortedStr] = [strs[i]]
        else:
            res[sortedStr].append(strs[i])

    return list(res.values())


print(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
