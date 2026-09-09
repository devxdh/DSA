def isValid(s: str):
    stack = []
    bracketMap = {")": "(", "]": "[", "}": "{"}

    for c in s:
        if c in bracketMap:
            if stack and stack[-1] == bracketMap[c]:
                stack.pop()
            else:
                return False

        else:
            stack.append(c)

    return len(stack) == 0


val = "()[]{}"
print(isValid(val))
