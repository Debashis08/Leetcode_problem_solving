/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution 
{
private:
    vector<Node*> visited;
    
    void run_dfs(Node* i,Node* new_node)
    {
        visited[new_node->val]=new_node;
        for(auto j:i->neighbors)
        {
            if(visited[j->val]==NULL)
            {
                Node* n_node=new Node(j->val);
                (new_node->neighbors).push_back(n_node);
                run_dfs(j,n_node);
            }
            else
            {
                (new_node->neighbors).push_back(visited[j->val]);
            }
        }
    }
public:
    Solution()
    {
        for(int i=0;i<102;i++)
    {
        visited.push_back(NULL);
    }
    }
    Node* cloneGraph(Node* node) 
    {
        if(node==NULL)
        {
            return NULL;
        }
        Node* copy_node=new Node(node->val);
        visited[node->val]=copy_node;
        for(auto i:node->neighbors)
        {
            if(visited[i->val]==NULL)
            {
                Node* new_node=new Node(i->val);
                (copy_node->neighbors).push_back(new_node);
                run_dfs(i,new_node);
            }
            else
            {
                (copy_node->neighbors).push_back(visited[i->val]);
            }
        }
    return copy_node;
    }
};