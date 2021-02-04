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

vector<ll> parent;

//using disjoint set and union
// Q link: https://www.spoj.com/problems/CLFLARR/

ll find(ll x)
{
	return parent[x] == x ? x : (parent[x] = find(parent[x]));
}

void setUnion(ll x, ll y)
{
	ll px = find(x);
	ll py = find(y);
	if (px != py)	
	{
		parent[px] = max(parent[px], parent[py]);
		parent[py] = max(parent[px], parent[py]);
	}
}

int main()
{
	layout();
	ll n, q;
	cin >> n >> q;
	ll l[q + 2], r[q + 2], c[q + 2];
	for (ll i = 1; i <= q; i++)
		cin >> l[i] >> r[i] >> c[i];
	ll res[n + 2] = {0};
	parent = vector<ll>(n + 2);
	for (ll i = 1; i <= n+1; i++)
		parent[i] = i;
	for (ll i = q; i >= 1; i--)
	{
		// cout << i << endl;
		ll index = find(l[i]);
		// cout << index << endl;
		while (index <= r[i])
		{
			res[index] = c[i];
			setUnion(index, index + 1);
			index = find(index);
		}
	}
	for (ll i = 1; i <= n; i++)
		cout << res[i] << endl;
}