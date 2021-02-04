//using recursion stack

class Solution {
public:
    bool util(int i,vector<int> adj[],int visited[], int rec[])
    {
        rec[i] = 1;
        visited[i] = 1;
        for(auto k:adj[i])
        {
            if(visited[k]==0)
            {
                if(util(k,adj,visited,rec))
                    return true;
            }
            else
            {
                if(rec[k]==1)
                    return true;
            }   
        }
        rec[i]=0;
        return false;
    }
    
	bool isCyclic(int V, vector<int> adj[]) {
	   	int visited[V] = {0};
	   	int rec[V] = {0};
	   	for(int i=0; i<V; i++)
	   	{
	   	    if(visited[i]==0)
	   	    {
	   	       if(util(i,adj,visited,rec))
	   	           return true;
	   	    }
	   	}
	   	return false;
	}
};