//
//  110_balanced_binary_tree.cpp
//  Leetcode
//
//  Created by Kaustubh Bansal on 14.02.22.
//

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
  bool isBalanced(TreeNode *root) {
    return height(root) >= 0;
  }
  
private:
  int height(TreeNode* root) {
    if(root == nullptr) {
      return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    if(left == -1 || right == -1) {
      return -1;
    }
    if(abs(left - right) <= 1) {
      return 1 + max(left, right);
    }
    return -1;
  }
};

int main() {
  return 0;
}
