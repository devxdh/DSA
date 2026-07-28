#include <iostream>
using namespace std;

/*
 * Pattern 1:
 * ****
 * ****
 * ****
 * ****
 */
int main() {
  int n = 4;
  for (int i = 0; i < n; i++) {
    cout << string(n, '*') << endl;
  }
}
