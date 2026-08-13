#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int ROWS = matrix.size();
    int COLS = matrix[0].size();

    int top = 0;
    int bot = ROWS - 1;

    while (top <= bot) {
        int row = (top + bot) / 2;

        if (target > matrix[row].back()) {
            top = row + 1;
        } else if (target < matrix[row].front()) {
            bot = row - 1;
        } else {
            break;
        }
    }

    if (!(top <= bot)) {
        return false;
    }

    int row = (top + bot) / 2;

    int l = 0;
    int r = COLS - 1;

    while (l <= r) {
        int m = (l + r) / 2;
        if (target > matrix[row][m]) {
            l = m + 1;
        } else if (target < matrix[row][m]) {
            r = m - 1;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << searchMatrix(matrix, 3) << endl;
    return 0;
}
