//
//  104_maximum_depth_of_binary_tree.cpp
//  Leetcode
//
//  Created by Kaustubh Bansal on 08.02.22.
//
#include <algorithm>
#include <cmath>
#include <iostream>
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
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  }
};