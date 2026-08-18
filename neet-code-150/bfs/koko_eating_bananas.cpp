#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h) {
    int l = 1;
    int r = *ranges::max_element(piles);
    int res = r;

    while (l <= r) {
        int k = l + (r - 1) / 2;
        int hours = 0;

        for (auto p : piles) {
            hours = ceil(p / k);
        }

        if (hours <= h) {
            res = min(res, k);
            r = k - 1;
        } else {
            l = k + 1;
        }
    }

    return res;
}
