#include <iostream>
#include <string>
using namespace std;

/*
 * Pattern 5:
 * *****
 * ****
 * ***
 * **
 * *
 */
int main() {
  int n = 5;

  for (int i = n; i > 0; i--) {
    cout << string(i, '*') << endl;
  }

  return 0;
}
