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
    TreeNode* root;
    vector<int> vec;
    TreeNode* bst_solve(int l,int r)
    {
        if(l>r)
        {
            return NULL;
        }
        if(l==r)
        {
            return (new TreeNode(vec[l]));
        }
        int mid=(l+r)/2;
        TreeNode* temp=new TreeNode(vec[mid]);
        temp->left=bst_solve(l,mid-1);
        temp->right=bst_solve(mid+1,r);
        return temp;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        vec=nums;
        if(nums.size()==1)
        {
            root=new TreeNode(nums[0]);
            return root;
        }
        int mid=nums.size()/2;
        root=new TreeNode(nums[mid]);
        root->left=bst_solve(0,mid-1);
        root->right=bst_solve(mid+1,nums.size()-1);
        return root;
    }
};