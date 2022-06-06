class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adjlist(numCourses);
        for(auto ite:prerequisites)
        {
            adjlist[ite[0]].push_back(ite[1]);
            indegree[ite[1]]+=1;
        }
        list<int> s;
        list<int> l;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                s.push_back(i);
            }
        }
        while(s.empty()!=true)
        {
            int temp=*(s.begin());
            s.pop_front();
            l.push_back(temp);
            for(auto ite:adjlist[temp])
            {
                indegree[ite]--;
                if(indegree[ite]==0)
                {
                    s.push_back(ite);
                }
            }
        }
        if(l.size()!=numCourses)
        {
            return {};
        }
        else
        {
            for(int i=0;i<indegree.size();i++)
            {
                if(indegree[i]!=0)
                {
                    return {};
                }
            }
        }
        vector<int> res;
        for(auto i:l)
        {
            res.push_back(i);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};