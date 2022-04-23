class Solution 
{
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        if(n==1)
        {
            return 1;
        }
        vector<int> person_known_to;
        vector<int> person_knows;
        for(int i=0;i<n+1;i++)
        {
            person_known_to.push_back(0);
            person_knows.push_back(0);
        }
        for(int i=0;i<trust.size();i++)
        {
            person_known_to[trust[i][1]]++;
            person_knows[trust[i][0]]++;
        }
        for(int i=0;i<n+1;i++)
        {
            if(person_known_to[i]==n-1 && person_knows[i]==0)
            {
                return i;
            }
        }
        return -1;
    }
};