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

ll dep[N], parent[N];

void dfs(unordered_map<ll, vector<ll>> &graph, ll cur, ll par)
{
	parent[cur] = par;
	for (auto k : graph[cur])
	{
		if (k != par)
		{
			dep[k] = dep[cur] + 1;
			dfs(graph, k, cur);
		}
	}
}

ll lca(ll u, ll v)
{
	if(u==v)
		return u;

	//We'll keep dept of u always greater
	if(dep[u]<dep[v])
		swap(u,v);

	//Bring em at same level
	while(dep[u]>dep[v])
		u=parent[u];

	//find ancestor
	while(u!=v)
	{
		u=parent[u];
		v=parent[v];
	}
	return u;
}

int main()
{
	layout();
	ll n, m;
	cin >> n >> m;
	unordered_map<ll, vector<ll>> graph;
	for (ll i = 0; i < m; i++)
	{
		ll x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(graph,1,0);
	// for(ll i=1; i<=n; i++)
	// 	cout << i << " " << parent[i] << " " << dep[i] << endl;
	cout << lca(18,19) << endl;
}

/*
Input
19 18
1 2
2 4
2 5
5 6
6 7
6 8
6 9
1 3
3 10
3 11
10 17
17 18
17 19
11 12
12 13
12 14
12 15
15 16
*/
