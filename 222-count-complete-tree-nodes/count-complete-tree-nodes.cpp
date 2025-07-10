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
    int countleft(TreeNode* node) {
        int h = 0;
        while (node) {
            h += 1;
            node = node->left;
        }
        return h;
    }

    int countright(TreeNode* node) {
        int h = 0;
        while (node) {
            h += 1;
            node = node->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int left=countleft(root);
        int right=countright(root);
        if(left==right){
            return (1<<left)-1;//2^n-1 
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};