#include <iostream>
using namespace std;

/*
 * Pattern 8:
 * *********
 *  *******
 *   *****
 *    ***
 *     *
 */

int main() {
  int n = 5;

  for (int i = n; i > 0; i--) {

    for (int j = i; j < n; j++) {
      cout << ' ';
    }

    for (int j = (2 * i - 1); j > 0; j--) {
      cout << '*';
    }

    cout << endl;
  }

  return 0;
}
