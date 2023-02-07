//
//  70_climbing_stairs.cpp
//  Leetcode
//
//  Created by Kaustubh Bansal on 02.07.21.
//

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        int a = 1, b = 2;
        while(n > 2) {
            b = a + b;
            a = b - a;
            --n;
        }
        return b;
    }
};

int main() {
    Solution sol;
    assert(sol.climbStairs(3) == 3);
    cout << "Success\n";
}
