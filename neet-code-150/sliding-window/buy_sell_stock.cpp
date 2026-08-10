#include <algorithm>
#include <iostream>
#include <vector>

int maxProfit_ON2(std::vector<int> &prices) {
    int maxP = 0;

    for (size_t i = 0; i < prices.size(); i++) {
        for (size_t j = i; j < prices.size(); j++) {
            maxP = std::max(maxP, (prices[j] - prices[i]));
        }
    }

    if (maxP <= 0) {
        return 0;
    }

    return maxP;
}

int maxProfit(std::vector<int> prices) {
    int maxP = 0;
    int left = 0;
    int right = 1;

    while (right < int(prices.size())) {
        if (prices[left] < prices[right]) {
            maxP = std::max(maxP, (prices[right] - prices[left]));
            right++;
        } else {
            left = right;
        }
        right++;
    }

    return maxP;
}

int main() {
    std::vector<int> orderBook = {7, 1, 5, 3, 6, 4};
    std::cout << maxProfit_ON2(orderBook) << std::endl;
    return 0;
}
