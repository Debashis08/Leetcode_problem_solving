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
    vector<vector<int>> res;
    vector<TreeNode*> q_obj;
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root==NULL)
        {
            return res;
        }
        q_obj.push_back(root);
        while(q_obj.empty()!=true)
        {
            vector<int> vec;
            int q_size=q_obj.size();
            for(int i=0;i<q_size;i++)
            {
                TreeNode* temp=*(q_obj.begin());
                q_obj.erase(q_obj.begin());
                vec.push_back(temp->val);
                if(temp->left!=NULL)
                {
                    q_obj.push_back(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q_obj.push_back(temp->right);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};