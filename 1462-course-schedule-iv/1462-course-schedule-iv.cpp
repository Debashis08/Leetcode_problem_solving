class Solution {
public:
    
    bool bfs(int sc , int de , vector<int>ans[] ,int n)
    {
       vector<bool>vis(n,false);
        
        queue<int>q;
        vis[sc]=true;
        
        q.push(sc);
        
        while(!q.empty())
        {
            int h = q.front();
            q.pop();
            
            for(auto &x : ans[h])
            {
                if(x==de)
                {
                    return true;
                }
                if(!vis[x])
                {
                    q.push(x);
                    vis[x]=true;
                }
            }
        }
        return false;
        
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        
        
        vector<int>ans[1007];
        vector<bool>res;
        //vector<bool>vis(n,false);
        
        for(auto &x: pre)
        {
           ans[x[0]].push_back(x[1]);
        }
        
        for(int i=0; i< queries.size(); i++)
        {
            vector<int>temp = queries[i];
            
            if(bfs(temp[0],temp[1],ans,n))
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        
        
        return res;
        
       
    }
};