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

ll timer;

void eulerTour1(unordered_map<ll, vector<ll>> &graph, ll cur, ll par, vector<ll> &tin, vector<ll> &tout)
{
	cout << cur << " ";
	tout[cur] = timer;
	tin[cur] = timer++;
	for (auto k : graph[cur])
	{
		if (k != par)
		{
			eulerTour1(graph, k, cur, tin, tout);
			cout << cur << " ";
			tout[cur] = timer++;
		}
	}
	// tout[cur] = timer++;
}

void eulerTour2(unordered_map<ll, vector<ll>> &graph, ll cur, ll par, vector<ll> &tin, vector<ll> &tout)
{
	tin[cur] = timer++;
	cout << cur << " ";
	for (auto k : graph[cur])
	{
		if (k != par)
		{
			eulerTour2(graph, k, cur, tin, tout);
		}
	}
	tout[cur] = timer++;
	cout << cur << " ";
}

void eulerTour3(unordered_map<ll, vector<ll>> &graph, ll cur, ll par, vector<ll> &tin, vector<ll> &tout)
{
	tin[cur] = ++timer;
	cout << cur << " ";
	for (auto k : graph[cur])
	{
		if (k != par)
		{
			eulerTour3(graph, k, cur, tin, tout);
		}
	}
	tout[cur] = timer;
}

bool isAncestor(vector<ll> &tin, vector<ll> &tout, ll par, ll child)
{
	if(tin[child]>=tin[par] && tout[child]<=tout[par])
		return true;
	return false;
}

int main()
{
	layout();
	ll n, m;
	cin >> n >> m;
	unordered_map<ll, vector<ll>> graph;
	vector<ll> tin(n + 1, 0);
	vector<ll> tout(n + 1, 0);
	for (ll i = 0; i < m; i++)
	{
		ll x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	timer = 0; // timer = 0 for tour 3
	// timer = 1 -> if tour 1 or 2
	eulerTour3(graph, 1, 1, tin, tout);
	cout << endl;
	for (ll i = 1; i <= n; i++)
	{
		cout << i << " " << tin[i] << " " << tout[i] << endl;
	}
	cout << isAncestor(tin,tout,1,2) << endl;
}