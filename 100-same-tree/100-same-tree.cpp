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
    vector<char> vec_p;
    vector<char> vec_q;
    bool flag=true;
    void push_element_p(TreeNode* temp)
    {
        if(temp!=NULL)
        {
            vec_p.push_back(char(temp->val));
            push_element_p(temp->left);
            push_element_p(temp->right);
        }
        else
        {
            vec_p.push_back('n');
        }
    }
    void push_element_q(TreeNode* temp)
    {
        if(temp!=NULL)
        {
            vec_q.push_back(char(temp->val));
            push_element_q(temp->left);
            push_element_q(temp->right);
        }
        else
        {
            vec_q.push_back('n');
        }   
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        push_element_p(p);
        push_element_q(q);
        if(vec_p.empty()==true && vec_q.empty()!=true)
        {
            return false;
        }
        else if(vec_p.empty()!=true && vec_q.empty()==true)
        {
            return false;
        }
        else if(vec_p.size()!=vec_q.size())
        {
            return false;
        }
        else
        {
            for(int i=0;i<vec_p.size();i++)
            {
                if(vec_p[i]!=vec_q[i])
                {
                    flag=false;
                    break;
                }
            }
        }
        return flag;
    }
};