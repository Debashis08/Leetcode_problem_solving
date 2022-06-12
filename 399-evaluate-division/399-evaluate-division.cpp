class Solution 
{
private:
    map<string,vector<pair<string,double>>> graph;
    map<string,int> visited;
    vector<double> result;
    double dfs_visit(string start,string end,double answer)
    {
        if(start==end)
        {
            return answer;
        }
        visited[start]=1;
        double res=-1.0000;
        for(auto i:graph[start])
        {
            string v=i.first;
            double w=i.second;
            if(visited[v]==0)
            {
                res=dfs_visit(v,end,answer*w);
                if(res!=-1.0000)
                {
                    break;
                }
            }
        }
        visited[start]=0;
        return res;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        for(int i=0;i<equations.size();i++)
        {
            string u=equations[i][0];
            string v=equations[i][1];
            double w=values[i];
            graph[u].push_back({v,w});
            graph[v].push_back({u,1/w});
            visited[u]=0;
            visited[v]=0;
        }
        result.resize(queries.size());

        for(int i=0;i<queries.size();i++)
        {
            string u=queries[i][0];
            string v=queries[i][1];
            if(graph.find(u)==graph.end() || graph.find(v)==graph.end())
            {
                result[i]=-1.0000;
            }
            else if(u==v)
            {
                result[i]=1.0000;
            }
            else
            {
                result[i]=dfs_visit(u,v,1);
            }
        }
        
        return result;
    }
};