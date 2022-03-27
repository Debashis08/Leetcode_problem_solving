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
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root==NULL)
        {
            return res;
        }
        TreeNode* curr=root;
        TreeNode* pre=NULL;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                res.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                pre=curr->left;
                while(pre->right!=NULL && pre->right!=curr)
                {
                    pre=pre->right;
                }
                if(pre->right==NULL)
                {
                    pre->right=curr;
                    curr=curr->left;
                }
                else
                {
                    pre->right=NULL;
                    res.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return res;
    }
};