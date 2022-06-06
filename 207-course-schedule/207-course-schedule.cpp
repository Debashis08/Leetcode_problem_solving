class Solution 
{
private:
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
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
            return false;
        }
        else
        {
            for(int i=0;i<indegree.size();i++)
            {
                if(indegree[i]!=0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};