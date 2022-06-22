class Solution 
{
private:
    map<int,vector<int>> adjlist;
    vector<int> color; //0-->white, 1-->red, 2-->blue
    vector<bool> visited;
    bool is_bipartite=true;
    void color_graph(int u,int cur_color)
    {
        if(color[u]!=0 && color[u]!=cur_color)
        {
            is_bipartite=false;
            return;
        }
        color[u]=cur_color;
        if(visited[u]==true)
        {
            return;
        }
        visited[u]=true;
        
        for(auto i:adjlist[u])
        {
            if(cur_color==1)
            {
                color_graph(i,2);
            }
            else
            {
                color_graph(i,1);
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        
        color.resize(n,0);
        visited.resize(n,false);
        
        for(int i=0;i<n;i++)
        {
            for(auto j:graph[i])
            {
                adjlist[i].push_back(j);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                color_graph(i,1);
            }
        }
        return is_bipartite;
    }
};