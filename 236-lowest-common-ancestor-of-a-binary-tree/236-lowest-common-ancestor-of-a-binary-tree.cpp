/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==NULL || p==root || q==root)
        {
            return root;
        }
        TreeNode* left_subtree=lowestCommonAncestor(root->left,p,q);
        TreeNode* right_subtree=lowestCommonAncestor(root->right,p,q);
        if(left_subtree==NULL)
        {
            return right_subtree;
        }
        else if(right_subtree==NULL)
        {
            return left_subtree;
        }
        else if(left_subtree!=NULL && right_subtree!=NULL)
        {
            return root;
        }
        else
        {
            return NULL;
        }
        return NULL;
    }
};