class Solution {
    map<int,vector<pair<int,int>>> adjlist;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> distance;
    vector<int> travel_time;
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        
        distance.resize(patience.size(),INT_MAX);
        for(auto i:edges)
        {
            adjlist[i[0]].push_back({i[1],1});
            adjlist[i[1]].push_back({i[0],1});
        }
        distance[0]=0;
        pq.push({0,0}); //distance,node
        while(pq.empty()!=true)
        {
            pair<int,int> temp=pq.top();
            pq.pop();
            for(auto i:adjlist[temp.second])
            {
                if(distance[i.first]>temp.first+i.second)
                {
                    distance[i.first]=temp.first+i.second;
                    pq.push({distance[i.first],i.first});
                }
            }
        }
        for(int i=0;i<distance.size();i++)
        {
            travel_time.push_back(2*distance[i]);
        }
        int ans=0;
        for(int i=1;i<travel_time.size();i++)
        {
            int t=travel_time[i];
            int p=patience[i];
            
            int total_messages_sent=t/p;
            if(t%p==0)
            {
                total_messages_sent--;
            }
            int last_message_time=total_messages_sent*p;
            int total_time=last_message_time+t+1;
            ans=max(ans,total_time);
        }
        return ans;
    }
};