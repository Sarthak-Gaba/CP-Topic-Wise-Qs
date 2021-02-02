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
ll dp[N],visited[N],depth[N];

// dp[i] gives the minimum depth among subchilds of node i
void minmSubchildDepth(unordered_map<ll,vector<ll>> &graph, ll cur, ll par, ll dep)
{
	visited[cur]=1;
	depth[cur] = dep;
	dp[cur] = dep;
	for(auto k:graph[cur])
	{
		if(visited[k]==0)
		{
			minmSubchildDepth(graph,k,cur,dep+1);
			dp[cur] = min(dp[cur],dp[k]);
		}
		else if(k!=par)
		{
			dp[cur] = min(dp[cur],depth[k]);
		}
	}
}

int main()
{
	layout();
	ll n,m;
	cin >> n >> m;
	unordered_map<ll,vector<ll>> graph;
	for(ll i=0; i<m; i++)
	{
		ll x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(ll i=0; i<n+1; i++)
		dp[i]=INT_MAX;
	minmSubchildDepth(graph,1,1,0);
	for(ll i=1; i<=n; i++)
		cout << i << " " << dp[i] << endl;
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