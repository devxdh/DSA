#include <iostream>
using namespace std;

/*
 * Pattern 2:
 * *
 * **
 * ***
 * ****
 * *****
 */
int main() {
  int n = 5;

  for (int i = 1; i <= n; i++) {
    cout << string(i, '*') << endl;
  }

  return 0;
}
