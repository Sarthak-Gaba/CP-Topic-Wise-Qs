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

struct node {
	ll v1, v2, key;
};

class Compare
{
public:
	bool operator() (node &a, node &b)
	{
		return a.key > b.key;
	}
};

ll find(ll d[], ll x)
{
	ll p = x;
	while (d[p] >= 0)
	{
		p = d[p];
	}
	//path compression
	while (d[x] >= 0)
	{
		ll i = d[x];
		d[x] = p;
		x = i;
	}
	return p;
}

int main()
{
	layout();
	ll V, E;
	cin >> V >> E;
	vector<pair<ll, ll>> graph[V];
	for (ll i = 0; i < E; i++)
	{
		ll x, y, w;
		cin >> x >> y >> w;
		graph[x].push_back(make_pair(y, w));
		graph[y].push_back(make_pair(x, w));
	}
	priority_queue<node, vector<node>, Compare> pq;
	for (auto k : graph[0])
	{
		struct node z;
		z.v1 = 0;
		z.v2 = k.first;
		z.key = k.second;
		pq.push(z);
	}
	ll counter = 0, visited[V] = {0}, ans = 0;
	while (!pq.empty() && counter < V - 1)
	{
		struct node z = pq.top();
		pq.pop();
		visited[z.v1] = 1;
		if (visited[z.v2] == 0)
		{
			visited[z.v2] = 1;
			ans += z.key;
			for (auto k : graph[z.v2])
			{
				if (visited[k.first] == 0)
				{
					struct node z;
					z.v1 = 0;
					z.v2 = k.first;
					z.key = k.second;
					pq.push(z);
				}
			}
			counter++;
		}
	}
	cout << ans << endl;
}