#include<bits/stdc++.h>
#include<bitset>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,
        tree_order_statistics_node_update>
        PBDS;

void layout()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

#define N 100

ll lowestTime[N],discoveryTime[N],timer;
vector<ll> articulationPoint;
vector<pair<ll,ll>> bridge;

void dfs(unordered_map<ll,vector<ll>> &graph, ll cur, ll par)
{
	discoveryTime[cur] = lowestTime[cur] = timer++;
	ll childs=0;
	for(auto k:graph[cur])
	{
		if(discoveryTime[k]==0)
		{
			childs++;
			dfs(graph,k,cur);
			lowestTime[cur] = min(lowestTime[cur],lowestTime[k]);
			if(par!=0 && lowestTime[k] >= discoveryTime[cur])
				articulationPoint.push_back(cur);
			if(lowestTime[k] > discoveryTime[cur])
				bridge.push_back(make_pair(cur,k));
		}
		else if(k!=par)
		{
			lowestTime[cur] = min(discoveryTime[cur],k);
		}
	}
	if(par==0 && childs>=2)
	{
		articulationPoint.push_back(cur);
	}
}

int main()
{
	layout();
	ll n,m;
	cin >> n >> m;
	unordered_map<ll,vector<ll>> graph;
	timer=1;
	for(ll i=0; i<m; i++)
	{
		ll x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(ll i=0; i<=n; i++)
	{
		lowestTime[i]=0;
		discoveryTime[i]=0;	
	}
	dfs(graph,1,0);
	for(auto k:articulationPoint)
		cout << k << " ";
	cout << endl;
	for(auto k:bridge)
		cout << k.first << "-" << k.second << " ";
	cout << endl;
}

// Input
// 12 16
// 1 3
// 1 9
// 9 12
// 12 11
// 11 9
// 3 5
// 5 7
// 7 3
// 5 1
// 3 6
// 6 1
// 6 2
// 2 8
// 8 3
// 2 4
// 4 10