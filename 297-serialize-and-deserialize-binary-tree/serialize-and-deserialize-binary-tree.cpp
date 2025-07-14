/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s="";
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();
            if(curr==NULL){
                s+="$,";
            }
            else{
                s+=to_string(curr->val)+",";
            }
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        } 
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            getline(ss, str, ',');
            // If the value is not "#", create a new
            // left child and push it to the queue
            if (str != "$") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                curr->left = leftNode;
                q.push(leftNode);
            }
            getline(ss, str, ',');
            // If the value is not "#", create a
            // new right child and push it to the queue
            if (str != "$") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                curr->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;

        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));