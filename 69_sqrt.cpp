

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int mySqrt(int n) {
    double guess = n / 2.0;
    while (!isClose(guess, n)) {
      guess = next(guess, n);
    }
    return guess;
  }

 private:
  double next(double x0, int n) {
    return x0 - (x0 * x0 - n) / 2 / x0;
  }

  bool isClose(double x, int n) {
    int fl = (int) x;
    int cl = fl + 1;
    return n >= fl * fl && n < cl * cl;
  }
};

int main() {
  Solution sol;
//    assert(sol.mySqrt(4) == 2);
  assert(sol.mySqrt(8) == 2);
  cout << "Success\n";
}
