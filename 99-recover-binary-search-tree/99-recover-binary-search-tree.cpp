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
    TreeNode* first=NULL;
    TreeNode* middle=NULL;
    TreeNode* last=NULL;
    TreeNode* prev=NULL;
    void inorder(TreeNode* temp)
    {
        if(temp==NULL)
        {
            return;
        }
        inorder(temp->left);
        if(prev!=NULL && temp->val<prev->val)
        {
            if(first==NULL)
            {
                first=prev;
                middle=temp;
            }
            else
            {
                last=temp;
            }
        }
        prev=temp;
        inorder(temp->right);
    }
public:
    void recoverTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root);
        if(first!=NULL && last!=NULL)
        {
            int t=first->val;
            first->val=last->val;
            last->val=t;
        }
        else
        {
            int t=first->val;
            first->val=middle->val;
            middle->val=t;
        }
    }
};