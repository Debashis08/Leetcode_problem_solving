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
    int maxDepth(TreeNode* root) 
    {
        queue<TreeNode*> q_obj;
        int depth=0;
        if(root!=NULL)
        {
            q_obj.push(root);
        }
        while(q_obj.empty()!=true)
        {
            int q_size=q_obj.size();
            depth++;
            for(int i=0;i<q_size;i++)
            {
                TreeNode* temp=q_obj.front();
                q_obj.pop();
                if(temp->left!=NULL)
                {
                    q_obj.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q_obj.push(temp->right);
                }
            }
        }
        return depth;
    }
};