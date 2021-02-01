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

// dp[i] gives the minimum value among subchilds of node i
void minmSubchild(unordered_map<ll,vector<ll>> graph, unordered_map<ll,ll> &dp, ll i, ll par)
{
	dp[i] = i;
	for(auto k:graph[i])
	{
		if(k!=par)
		{
			minmSubchild(graph,dp,k,i);
			dp[i] = min(dp[i],dp[k]);
		}
	}
}

int main()
{
	layout();
	ll n,m;
	cin >> n >> m;
	unordered_map<ll,vector<ll>> graph;
	unordered_map<ll,ll> dp;
	for(ll i=0; i<m; i++)
	{
		ll x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	minmSubchild(graph,dp,1,1);
	for(auto k:dp)
	{
		cout << k.first << " " << k.second << endl;
	}
}