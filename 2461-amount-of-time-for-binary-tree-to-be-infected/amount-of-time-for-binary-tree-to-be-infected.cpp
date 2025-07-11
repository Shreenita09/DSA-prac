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
    // Step 1: Map each node to its parent
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    // Step 2: Find the node that matches the target value
    TreeNode* findTarget(TreeNode* root, int target) {
        if (!root) return nullptr;
        if (root->val == target) return root;
        TreeNode* left = findTarget(root->left, target);
        if (left) return left;
        return findTarget(root->right, target);
    }

    // Step 3: BFS to spread the infection
    int amountOfTime(TreeNode* root, int target) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        TreeNode* targetNode = findTarget(root, target);  // Fix here
        unordered_map<TreeNode*, bool> visited;

        queue<TreeNode*> q;
        q.push(targetNode);
        visited[targetNode] = true;

        int curr_time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool spread = false;

            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                // Spread to left child
                if (curr->left && !visited[curr->left]) {
                    spread = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                // Spread to right child
                if (curr->right && !visited[curr->right]) {
                    spread = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                // Spread to parent
                if (parent[curr] && !visited[parent[curr]]) {
                    spread = true;
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }

            if (spread) curr_time++;  // Only increment if infection spread in this minute
        }

        return curr_time;
    }
};
