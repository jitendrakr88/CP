
#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int count=0;
public:
    // O(n). Can be done better using binary search
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        countNodes(root->left);
        count++;
        countNodes(root->right);
        return count;
    }
};

