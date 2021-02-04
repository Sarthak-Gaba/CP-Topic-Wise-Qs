class Solution{
	public:
	
	vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> res;
        int indegree[V] = {0};
        for(int i=0; i<V; i++)
        {
            for(auto k:adj[i])
                indegree[k]++;
        }
        queue<int> q;
        for(int i=0; i<V; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto k:adj[node])
            {
                indegree[k]--;
                if(indegree[k]==0)
                    q.push(k);
            }
        }
        // for(auto i:res)
        //     cout << i << " ";
        // cout << endl;
        return res;
	}
};