class Solution {
private:
    map<string,vector<string>> adjlist;
    unordered_map<string,int> indegree;
    vector<string> res;
    queue<string> q_obj;
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        for(int i=0;i<recipes.size();i++)
        {
            for(int j=0;j<ingredients[i].size();j++)
            {
                adjlist[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        for(auto i:supplies)
        {
            q_obj.push(i);
        }
        while(q_obj.empty()!=true)
        {
            string temp=q_obj.front();
            q_obj.pop();
            for(auto i:adjlist[temp])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q_obj.push(i);
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};