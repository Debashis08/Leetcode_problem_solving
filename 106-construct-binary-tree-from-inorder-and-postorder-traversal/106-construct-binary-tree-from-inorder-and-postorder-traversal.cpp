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
    vector<int> vec_in;
    vector<int> vec_post;
    int curr;
    int search_in_inorder(int el)
    {
        for(int i=0;i<vec_in.size();i++)
        {
            if(el==vec_in[i])
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* insert_node(int left,int right)
    {
        if(left>right)
        {
            return NULL;
        }
        int index=search_in_inorder(vec_post[curr]);
        curr--;
        TreeNode* temp=new TreeNode(vec_in[index]);
        if(left==right)
        {
            return temp;
        }
        temp->right=insert_node(index+1,right);
        temp->left=insert_node(left,index-1);
        return temp;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        vec_in=inorder;
        vec_post=postorder;
        curr=vec_post.size()-1;
        return (insert_node(0,inorder.size()-1));
    }
};