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
    void rightview(TreeNode* temp,int level)
    {
        if(temp==NULL)
        {
            return;
        }
        if(res.size()==level)
        {
            res.push_back(temp->val);
        }
        rightview(temp->right,level+1);
        rightview(temp->left,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root==NULL)
        {
            return res;
        }
        rightview(root,0);
        return res;
    }
};