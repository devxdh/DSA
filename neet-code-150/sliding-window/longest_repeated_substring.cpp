#include <algorithm>
#include <iostream>
#include <unordered_map>

int characterReplacement(std::string s, int k) {
    std::unordered_map<char, int> count;
    int res = 0;
    int l = 0;
    int max_f = 0;

    for (int r = 0; r < static_cast<int>(s.size()); r++) {
        count[s[r]]++;
        max_f = std::max(max_f, count[s[r]]);

        while ((r - l + 1) - max_f > k) {
            count[s[l]]--;
            l++;
        }

        res = std::max(res, r - l + 1);
    }

    return res;
}

int main() {
    std::cout << characterReplacement("ABAB", 2) << std::endl;
    return 0;
}
