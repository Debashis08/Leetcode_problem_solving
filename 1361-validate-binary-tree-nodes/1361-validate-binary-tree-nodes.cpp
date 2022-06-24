class Solution {
private:
    map<int,vector<int>> adjlist;
    vector<int> indegree;
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        indegree.resize(n,0);
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                adjlist[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(rightChild[i]!=-1)
            {
                adjlist[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
            }
        }
        queue<int> q_obj;
        vector<int> vec;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]>1)
            {
                return false;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                root=i;
            }
        }
        if(root==-1)
        {
            return false;
        }
        else
        {
            q_obj.push(root);
        }
        while(q_obj.empty()!=true)
        {
            int temp=q_obj.front();
            q_obj.pop();
            vec.push_back(temp);
            for(auto i:adjlist[temp])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q_obj.push(i);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]!=0)
            {
                return false;
            }
        }
        return true;
        
    }
};