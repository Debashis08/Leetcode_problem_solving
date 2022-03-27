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
    queue<TreeNode*> q_obj;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        if(root==NULL)
        {
            return res;
        }
        q_obj.push(root);
        while(q_obj.empty()!=true)
        {
            int q_size=q_obj.size();
            vector<int> vec;
            for(int i=0;i<q_size;i++)
            {
                TreeNode* temp=q_obj.front();
                q_obj.pop();
                vec.push_back(temp->val);
                if(temp->left!=NULL)
                {
                    q_obj.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q_obj.push(temp->right);
                }
            }
            res.insert(res.begin(),vec);
        }
        return res;
    }
};