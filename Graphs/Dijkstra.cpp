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

void dijkstra(vector<pair<ll, ll>> graph[], ll dist[], ll src, ll V)
{
	dist[src] = 0;
	ll visited[V + 1] = {0};
	set<pair<ll, ll>> store;
	store.insert(make_pair(0, src));
	while (store.size() > 0)
	{
		pair<ll, ll> p = *(store.begin());
		store.erase(store.begin());
		ll node = p.second;
		ll weight = p.first;
		visited[node] = 1;
		for (auto k : graph[node])
		{
			if (visited[k.first] == 0 && weight + k.second < dist[k.first])
			{
				auto f = store.find(make_pair(dist[k.first], k.first));
				if (f != store.end())
					store.erase(f);
				dist[k.first] = weight + k.second;
				store.insert(make_pair(dist[k.first], k.first));
			}
		}
	}
}

int main()
{
	layout();
	ll t;
	cin >> t;
	while (t--)
	{
		ll V, E, src;
		cin >> V >> E;
		vector<pair<ll, ll>> graph[V + 1];
		for (ll i = 0; i < E; i++)
		{
			ll x, y, w;
			cin >> x >> y >> w;
			graph[x].push_back(make_pair(y, w));
			graph[y].push_back(make_pair(x, w));
		}
		cin >> src;
		ll dist[V + 1];
		for (ll i = 0; i <= V; i++)
			dist[i] = INT_MAX;
		dijkstra(graph,dist,src,V);
		for(ll i=1; i<=V; i++)
		{
			if(i==src)
				continue;
			if(dist[i]==INT_MAX)
				cout << -1 << " ";
			else
				cout << dist[i] << " ";
		}
		cout << endl;
	}
}