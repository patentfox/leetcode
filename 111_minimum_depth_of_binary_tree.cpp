

#include <algorithm>
#include <cmath>
#include <iostream>
#include <span>
#include <string>
#include <vector>

#include "utils.h"
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    if (left == 0 && right == 0) {
      return 1;
    }
    if (left == 0 || right == 0) {
      return left + right + 1;
    }
    return std::min(left, right) + 1;
  }
};
