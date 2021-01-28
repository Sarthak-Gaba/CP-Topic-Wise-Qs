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

class Graph {
	unordered_map<ll, vector<ll>> m;
public:
	Graph(ll n) {
		for (ll i = 0; i < n; i++)
		{
			m[i].push_back(i);
		}
	}
	void addEdge(ll, ll);
	void bfs(ll);
	void dfs(ll);
	void sssp(ll);
	void shortestPath(ll, ll);
	void con_comp();
};

void Graph :: addEdge(ll x, ll y)
{
	m[x].push_back(y);
	m[y].push_back(x);
}

void Graph :: bfs(ll src)
{
	queue<ll> q;
	unordered_map<ll, ll> visited;
	visited[src] = 1;
	q.push(src);
	while (!q.empty())
	{
		ll node = q.front();
		q.pop();
		cout << node << " ";
		for (auto i : m[node])
		{
			if (visited[i] == 0)
			{
				q.push(i);
				visited[i] = 1;
			}
		}
	}
	cout << endl;
}

void Graph :: sssp(ll src)
{
	queue<ll> q;
	unordered_map<ll, ll> dist;
	q.push(src);

	for (auto i : m)
		dist[i.first] = INT_MAX;
	dist[src] = 0;

	while (!q.empty())
	{
		ll node = q.front();
		q.pop();
		for (auto i : m[node])
		{
			if (dist[i] == INT_MAX)
			{
				q.push(i);
				dist[i] = dist[node] + 1;
			}
		}
	}

	for (auto i : dist)
	{
		if (i.second == INT_MAX)
			cout << i.first << " -> No Path" << endl;
		else
			cout << i.first << " -> " << i.second << endl;
	}
}

void Graph :: shortestPath(ll src, ll dest)
{
	queue<pair<ll, ll>> q;
	ll parent[50] = {0};
	unordered_map<ll, ll> visited;
	q.push(make_pair(src, 0));
	visited[src] = 1;
	while (!q.empty())
	{
		pair<ll, ll> node = q.front();
		q.pop();
		for (auto i : m[node.first])
		{
			if (visited[i] == 0)
			{
				if (i == dest)
				{
					cout << "Shortest distance: " << node.second + 1 << endl;
					ll i = dest;
					parent[i] = node.first;
					cout << "Path: ";
					while (i != src)
					{
						cout << i << "<-";
						i = parent[i];
					}
					cout << src << endl;
					return;
				}
				parent[i] = node.first;
				q.push(make_pair(i, node.second + 1));
				visited[i] = 1;
			}
		}
	}
	cout << "Path not found" << endl;
}

void util_dfs(ll i, unordered_map<ll, ll> &visited, unordered_map<ll, vector<ll>> &m, ll &counter)
{
	// cout << i << " ";
	for (auto k : m[i])
	{
		if (visited[k] == 0)
		{
			counter++;
			visited[k] = 1;
			util_dfs(k, visited, m, counter);
		}
	}
}

// void Graph :: dfs(ll src)
// {
// 	unordered_map<ll, ll> visited;
// 	visited[src] = 1;
// 	util_dfs(src, visited, m, 0);
// }

void Graph :: con_comp()
{
	ll counter = 0;
	unordered_map<ll, ll> visited;
	bool flag = true;
	vector<ll> values;
	ll value;
	for (auto i : m)
	{
		if (visited[i.first] == 0)
		{
			value = 1;
			visited[i.first] = 1;
			counter++;
			util_dfs(i.first, visited, m, value);
			values.push_back(value);
		}
	}
	ll sum = 0, ans = 0;
	for (ll i = 0; i < values.size(); i++)
		sum += values[i];
	for (ll i = 0; i < values.size(); i++) +
	{
		ans += (sum - values[i]) * values[i];
		sum -= values[i];
	}
	cout << ans << endl;
}


int main()
{
	layout();
	ll n, p;
	cin >> n >> p;
	Graph G(n);
	for (ll i = 0; i < p; i++)
	{
		ll x, y;
		cin >> x >> y;
		G.addEdge(x, y);
	}
	G.con_comp();
}