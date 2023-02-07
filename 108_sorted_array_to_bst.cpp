//
//  108_sorted_array_to_bst.cpp
//  Leetcode
//
//  Created by Kaustubh Bansal on 08.02.22.
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <span>

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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    TreeNode* root = nullptr;
    helper(nums, 0, (int)nums.size()-1, &root);
    return root;
  }
  
private:
  void helper(const vector<int>& nums, int start, int end, TreeNode** root) {
    if(start <= end) {
      int mid = (start + end)/2;
      *root = new TreeNode(nums[mid]);
      helper(nums, start, mid-1, &(*root)->left);
      helper(nums, mid+1, end, &(*root)->right);
    }
  }
};
