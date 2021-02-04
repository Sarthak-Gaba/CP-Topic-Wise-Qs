class Solution{
	public:
	void dfs(int i, vector<int> adj[], int visited[], vector<int> &res)
    {
        visited[i]=1;
        for(auto k:adj[i])
        {
            if(visited[k]==0)
            {
                dfs(k,adj,visited,res);
            }
        }
        res.push_back(i);
    }
	
	vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> res;
        int visited[V] = {0};
        for(int i=0; i<V; i++)
        {
            if(visited[i]==0)
            {
                dfs(i,adj,visited,res);
            }
        }
        reverse(res.begin(),res.end());
        // for(auto i:res)
        //     cout << i << " ";
        // cout << endl;
        return res;
	}
};