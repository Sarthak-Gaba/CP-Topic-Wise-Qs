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

// class Compare
// {
// public:
// 	bool operator() (node &a, node &b)
// 	{
// 		return a.key > b.key;
// 	}
// };

bool compare(node n1, node n2)
{
	return n1.key < n2.key;
}

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

void setUnion(ll d[], ll x, ll y)
{
	ll p1 = find(d, x);
	ll p2 = find(d, y);
	if (d[p1] <= d[p2])
	{
		d[p1] += d[p2];
		d[p2] = p1;
	}
	else
	{
		d[p2] += d[p1];
		d[p1] = p2;
	}
}

int main()
{
	layout();
	ll V, E;
	cin >> V >> E;
	vector<node> store;
	ll d[V];
	for (ll i = 0; i < V; i++)
		d[i] = -1;
	for (ll i = 0; i < E; i++)
	{
		ll x, y, w;
		cin >> x >> y >> w;
		struct node z;
		z.v1 = x;
		z.v2 = y;
		z.key = w;
		store.push_back(z);
	}
	sort(store.begin(), store.end(), compare);
	ll counter = 0, ans = 0, k = 0;
	while (counter < V - 1)
	{
		struct node z = store[k];
		ll p1 = find(d, z.v1);
		ll p2 = find(d, z.v2);
		if (p1 != p2)
		{
			setUnion(d, z.v1, z.v2);
			ans += z.key;
			counter++;
		}
		k++;
	}
	cout << ans << endl;
}