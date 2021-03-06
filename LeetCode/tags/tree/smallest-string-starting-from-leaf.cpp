#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
// #define MOD 1000000007

bool az(int x) { return 97<=x && x<=122; }
bool AZ(int x) { return 65<=x && x<=90; }
bool number(int x) { return 48<=x && x<=57; }

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
public:
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        string ans = string(8500, 'z'), r="";
        char c = root->val + 'a';
        queue<pair<TreeNode*, string>> q;
        q.push(make_pair(root, r + c));
        while(!q.empty()) {
            TreeNode* f = q.front().first;
            string word = q.front().second;
            q.pop();
            if(f->left==NULL && f->right==NULL) {
                if(word < ans)
                    ans = word;
            } else {
                if(f->left) {
                    c = f->left->val + 'a';
                    q.push(make_pair(f->left, c + word));
                }
                if(f->right) {
                    c = f->right->val + 'a';
                    q.push(make_pair(f->right, c + word));
                }
            }
        }
        return ans;
    }
};


