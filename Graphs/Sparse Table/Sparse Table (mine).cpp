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

vector<ll> power;
vector<ll> logTwo;

void build(vector<vector<ll>> &sparse, ll arr[], ll n)
{
	for (ll i = 0; i < n; i++)
	{
		sparse[i] = vector<ll>(logTwo[n] + 1);
		sparse[i][0] = arr[i];
	}
	for (ll j = 1; power[j] <= n; j++)
	{
		for (ll i = 0; i + power[j] - 1 < n; i++)
			sparse[i][j] = min(sparse[i][j - 1], sparse[i + power[j-1]][j - 1]);
	}
}

ll query(vector<vector<ll>> &sparse, ll x, ll y)
{
	ll gap = y - x + 1;
	ll k = logTwo[gap];
	return min(sparse[x][k], sparse[x + gap - power[k]][k]);
}

void buildPower()
{
	power[0]=1;
	for(ll i=1; i<power.size(); i++)
	{
		power[i] = 2*power[i-1];
	}
}

void buildLog()
{
	logTwo[1]=0;
	for(ll i=2; i<logTwo.size(); i++)
	{
		logTwo[i] = logTwo[i/2]+1;
	}
}

int main()
{
	layout();
	ll n;
	cin >> n;
	ll arr[n];
	logTwo = vector<ll>(n+1);
	buildLog();
	power = vector<ll>(logTwo[n] + 1);
	buildPower();
	for (ll i = 0; i < n; i++)
		cin >> arr[i];
	vector<vector<ll>> sparse(n);
	build(sparse, arr, n);
	// for (ll i = 0; i < n; i++)
	// {
	// 	for (ll j = 0; power[j] <= n; j++)
	// 	{
	// 		if(i+power[j]-1>=n)
	// 			break;
	// 		cout << sparse[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	cout << query(sparse, 3, 4) << endl;
}

/*
Input
6
4 6 1 5 2 6
*/
