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
    bool check(TreeNode* p,TreeNode* q){
        if(p==nullptr && q==nullptr){
            return true;
        }else if(p==nullptr || q==nullptr){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        return check(p->left,q->left) && check(p->right,q->right);   
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode* p=root;
        bool ans=false;
        queue<TreeNode*>q;
        q.push(p);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==subRoot->val){
                ans= check(node,subRoot);
                if(ans){
                    return true;
                    break;
                }
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        return ans;
    }
};
