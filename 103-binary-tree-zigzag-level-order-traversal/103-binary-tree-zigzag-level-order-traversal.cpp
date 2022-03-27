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
    vector<vector<int>> res;
    queue<TreeNode*> q_obj;
    bool flag=true;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root==NULL)
        {
            return res;
        }
        q_obj.push(root);
        while(q_obj.empty()!=true)
        {
            int q_size=q_obj.size();
            vector<int> vec(q_size,0);
            for(int i=0;i<q_size;i++)
            {
                TreeNode* temp=q_obj.front();
                q_obj.pop();
                if(flag==true)
                {
                    vec[i]=temp->val;
                }
                else
                {
                    vec[q_size-1-i]=temp->val;
                }
                if(temp->left!=NULL)
                {
                    q_obj.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q_obj.push(temp->right);
                }
            }
            res.push_back(vec);
            if(flag==true)
            {
                flag=false;
            }
            else
            {
                flag=true;
            }
        }
        return res;
    }
};