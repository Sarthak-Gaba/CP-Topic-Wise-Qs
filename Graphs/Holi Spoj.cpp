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
 
ll util(ll i, unordered_map<ll, ll> &visited, unordered_map<ll, vector<pair<ll, ll>>> &graph, ll counter, ll &res, ll edges)
{
	ll r = 0;
	for (auto j : graph[i])
	{
		if (visited[j.first] == 0)
		{
			visited[j.first] = 1;
			ll x = util(j.first, visited, graph, counter + 1, res, edges);
			res += 2 * min(x, edges - x) * j.second;
			r += x;
		}
	}
	return r + 1;
}
 
int main()
{
	layout();
	ll t;
	cin >> t;
	for(ll z=1; z<=t; z++)
	{
		ll n;
		cin >> n;
		unordered_map<ll, vector<pair<ll, ll>>> graph;
		unordered_map<ll, ll> visited;
		ll counter = 1, res = 0;
		for (ll i = 0; i < n - 1; i++)
		{
			ll x, y, w;
			cin >> x >> y >> w;
			graph[x].push_back(make_pair(y, w));
			graph[y].push_back(make_pair(x, w));
		}
		util(1, visited, graph, counter, res, n);
		cout << "Case #" << z << ": " << res << endl;
	}
} 