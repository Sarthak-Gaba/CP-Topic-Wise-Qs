class Solution {
public:
    bool util(int i, unordered_map<ll,ll> &visited, vector<ll> adj[], ll parent)
    {
        visited[i]=1;
        for(auto k:adj[i])
        {
            if(visited[k]!=0)
            {
                return true;
            }
            if(visited[k]==0)
            {
                if(util(k,visited,adj,i))
                    return true;
            }
        }
        return false;
    }
    
	bool isCyclic(int V, vector<int> adj[]) {
	   	unordered_map<ll,ll> visited;
	   	for(int i=0; i<V; i++)
	   	{
	   	    if(visited[i]==0)
	   	    {
	   	       if(util(i,visited,adj,0))
	   	            return true;
	   	    }
	   	}
	   	return false;
	}
};