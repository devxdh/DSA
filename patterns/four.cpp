#include <iostream>
using namespace std;

/*
 * Patter 4:
 * 1
 * 22
 * 333
 * 4444
 * 55555
 */

void betterSolution();

int main() {
  int n = 5;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << i;
    }

    cout << endl;
  }

  cout << "\nO(n) Solution" << endl;
  betterSolution();

  return 0;
}

void betterSolution() {
  int n = 5;

  for (int i = 1; i <= n; i++) {
    cout << string(i, '0' + i) << endl;
  }
}
