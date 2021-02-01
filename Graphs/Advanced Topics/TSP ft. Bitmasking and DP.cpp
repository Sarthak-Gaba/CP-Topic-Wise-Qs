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

ll visitedAll;
ll dp[1<<12+7][15];

//Q link: https://practice.geeksforgeeks.org/problems/travelling-salesman-problem/0

ll tsp(vector<vector<ll>> &graph, ll mask, ll i, ll &n)
{
	if (mask == visitedAll)
		return graph[i][0];

	if(dp[mask][i]!=-1)
		return dp[mask][i];

	ll ans = INT_MAX;
	for (ll k = 0; k < n; k++)
	{
		if (!((1 << k)&mask))
		{
			ll curAns = graph[i][k] + tsp(graph, mask | (1 << k), k, n);
			ans = min(curAns, ans);
		}
	}
	dp[mask][i] = ans;
	return ans;
}

int main()
{
	layout();
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		vector<vector<ll>> graph(n);
		for(ll i=0; i<((1<<n)+7); i++)
		{
			for(ll j=0; j<n+1; j++)
				dp[i][j]=-1;
		}
		visitedAll = (1 << n) - 1;
		for (ll i = 0; i < n; i++)
		{
			for (ll j = 0; j < n; j++)
			{
				ll x;
				cin >> x;
				graph[i].push_back(x);
			}
		}
		cout << tsp(graph,1,0,n) << endl;
	}
}