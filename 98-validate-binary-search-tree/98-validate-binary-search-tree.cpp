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
class Solution 
{
private:
    bool check_bst(TreeNode* temp,long long int l,long long int r)
    {
        if(temp==NULL)
        {
            return true;
        }
        else if(temp->val>l && temp->val<r)
        {
            return (check_bst(temp->left,l,temp->val)&&check_bst(temp->right,temp->val,r));
        }
        else
        {
            return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) 
    {
        return (check_bst(root,INT64_MIN,INT64_MAX));
    }
};