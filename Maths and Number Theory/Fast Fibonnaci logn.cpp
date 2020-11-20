#include<bits/stdc++.h>
#include<bitset>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define hash unordered_map<ll,ll>

typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,
tree_order_statistics_node_update>
PBDS;

#define mod 1000000007

void layout()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<vector<ll>> mul(vector<vector<ll>> v, vector<vector<ll>> v2, ll k)
{
	ll x, y, z;
	vector<vector<ll>> ans(k, vector<ll>(k, 0));
	for (x = 0; x < k; x++)
	{
		for (y = 0; y < k; y++)
		{
			for (z = 0; z < k; z++)
			{
				ans[x][y] = (ans[x][y] + (v[x][z] * v2[z][y]) % mod) % mod ;
			}
		}
	}
	return ans;
}
vector<vector<ll>> power(vector<vector<ll>> v, ll n, ll k)
{
	if (n == 1)
		return v;
	if (n & 1)
	{
		return mul(v, power(v, n - 1, k), k);
	}
	//return mul(v, power(v, n / 2, k), k);
	vector<vector<ll>> temp = power(v, n / 2, k);
	return mul(temp, temp, k);
}
ll findfib(ll n)
{
	vector<vector<ll>>one(2, vector<ll>(2));
	one[0][0] = 0;
	one[0][1] = 1;
	one[1][1] = 1;
	one[1][0] = 1;
	vector<ll>two (2);
	two[0] = 1;
	two[1] = 1;
	if (n == 1 || n == 2)
		return 1;
	one = power(one, n - 2, 2);
	return (one[1][1] + one[1][0]) % mod;

}

int main()
{
	layout();

}