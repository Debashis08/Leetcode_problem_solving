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
    bool flag=true;
    void check_symmetry(TreeNode* left_node,TreeNode* right_node)
    {
        if(left_node==NULL && right_node==NULL)
        {
            return;
        }
        else if(left_node!=NULL && right_node!=NULL)
        {
            if(left_node->val==right_node->val)
            {
                check_symmetry(left_node->left,right_node->right);
                check_symmetry(left_node->right,right_node->left);
            }
            else
            {
                flag=false;
                return;
            }
        }
        else
        {
            flag=false;
            return;
        }
    }
public:
    bool isSymmetric(TreeNode* root) 
    {
        check_symmetry(root->left,root->right);
        return flag;
    }
};