#include<bits/stdc++.h>
#include<bitset>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define pb push_back

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
vector<ll> power;
vector<ll> logTwo;

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

void build(vector<vector<ll>> &sparse, ll n)
{
	for (ll i = 1; i <= n; i++)
	{
		sparse[i] = vector<ll>(logTwo[n] + 2);
		sparse[i][0] = parent[i];
	}
	for (ll j = 1; power[j] <= n; j++)
	{
		for (ll i = power[j] + 1; i <= n; i++)
		{
			if (sparse[i][j - 1] == 0)
				sparse[i][j] = 0;
			else
				sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
		}
	}
}

ll lca(vector<vector<ll>> &sparse, ll u, ll v, ll n)
{
	if (u == v)
		return u;

	//We'll keep dept of u always greater
	if (dep[u] < dep[v])
		swap(u, v);

	//Bring em at same level
	ll dif = dep[u] - dep[v];
	ll x = 0;
	while (dif)
	{
		if (dif & 1)
			u = sparse[u][x];
		dif = dif >> 1;
		x++;
	}
	if (u == v)
		return u;

	//Keep movin up until ancestor is found
	ll k = logTwo[n] + 1;
	while (k >= 0)
	{
		if (sparse[u][k] != sparse[v][k])
		{
			u = sparse[u][k];
			v = sparse[v][k];
		}
		k--;
	}
	return parent[u];
}

void buildPower()
{
	power[0] = 1;
	for (ll i = 1; i < power.size(); i++)
	{
		power[i] = 2 * power[i - 1];
	}
}

void buildLog()
{
	logTwo[1] = 0;
	for (ll i = 2; i < logTwo.size(); i++)
	{
		logTwo[i] = logTwo[i / 2] + 1;
	}
}

int main()
{
	layout();
	// ll n;
	// cin >> n;
	// ll arr[n];
	// for (ll i = 0; i < n; i++)
	// 	cin >> arr[i];
	ll n, m;
	cin >> n >> m;
	logTwo = vector<ll>(n + 1);
	buildLog();
	power = vector<ll>(logTwo[n] + 2);
	buildPower();
	unordered_map<ll, vector<ll>> graph;
	for (ll i = 0; i < m; i++)
	{
		ll x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(graph, 1, 0);
	vector<vector<ll>> sparse(n + 1);
	// for(ll i=1; i<=n; i++)
	// 	cout << i << " " << parent[i] << endl;
	build(sparse, n);
	// for (ll i = 1; i <= n; i++)
	// {
	// 	for (ll j = 0; power[j] <= n; j++)
	// 		cout << sparse[i][j] << " ";
	// 	cout << endl;
	// }
	cout << lca(sparse, 7, 5, n);
	// cout << endl;
	// cout << query(sparse, 3, 4) << endl;
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
