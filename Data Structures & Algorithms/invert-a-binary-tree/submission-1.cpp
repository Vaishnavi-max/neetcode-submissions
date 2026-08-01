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
    void invert(TreeNode* node,TreeNode* l,TreeNode* r){
        if((!node)||(node->left==nullptr && node->right==nullptr)){
            return;
        }
        node->left=r;
        node->right=l;
        if(node->left){
            invert(node->left,node->left->left,node->left->right);
        }
        if(node->right){
            invert(node->right,node->right->left,node->right->right);
        }
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        invert(root,root->left,root->right);
        return root;
    }
};
