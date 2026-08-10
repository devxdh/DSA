#include <algorithm>
#include <iostream>
#include <vector>

int lengthOfLongestSubstring(std::string s) {
    std::vector<int> charCount(256, 0);

    int maxLength = 0;
    int left = 0;

    for (size_t right = 0; right < s.size(); right++) {
        charCount[s[right]]++;

        while (charCount[s[right]] > 1) {
            charCount[s[left]]--;
            left++;
        }

        int currentWindowMax = right - left + 1;
        maxLength = std::max(maxLength, currentWindowMax);
    }

    return maxLength;
}

int main() {
    std::cout << lengthOfLongestSubstring("abcabcbb") << std::endl;
    return 0;
}
