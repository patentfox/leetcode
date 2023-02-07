#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    string result;
    int i = (int) a.size() - 1, j = (int) b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0) {
      int a_i = i < 0 ? 0 : a[i] - '0';
      int b_j = j < 0 ? 0 : b[j] - '0';
      int sum = a_i + b_j + carry;
      result += sum % 2 + '0';
      carry = sum / 2;
      --i;
      --j;
    }
    if (carry == 1) {
      result += "1";
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution sol;
  assert(sol.addBinary("10", "11") == "101");
  assert(sol.addBinary("10", "10") == "100");
  assert(sol.addBinary("10", "110") == "1000");
  assert(sol.addBinary("10", "1") == "11");
  cout << "Success\n";
}
