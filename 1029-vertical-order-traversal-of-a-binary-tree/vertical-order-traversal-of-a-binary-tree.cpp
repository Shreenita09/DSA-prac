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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int,map<int,multiset<int>>> nodes;//vertical,level,nodes(sorted i.e multiset(duplicates))
       queue<pair<TreeNode*,pair<int,int>>> tr;//nodes,vertical,level;
       tr.push({root,{0,0}}); 
       while(!tr.empty()){
        auto p=tr.front();
        tr.pop();
        TreeNode* node=p.first; // the node;
        int x=p.second.first; // vertical;
        int y=p.second.second; //level
        nodes[x][y].insert(node->val);//in vertical level insert node er val in map;
        if(node->left){
            tr.push({node->left,{x-1,y+1}});
            
        } 
        if(node->right){
            tr.push({node->right,{x+1,y+1}});   
        }

       }
       vector<vector<int>> res;
       for(auto it:nodes){
        vector<int> vertical;
        for(auto p:it.second){
            vertical.insert(vertical.end(),p.second.begin(),p.second.end());

        }
        res.push_back(vertical);
       }
       return res;
    }
};