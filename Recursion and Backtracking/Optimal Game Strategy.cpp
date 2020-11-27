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

void layout()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
ll z=10007;

ll **dp;

ll util(ll a[], ll l, ll r)
{
	if(l>=r)
		return 0;
	if(dp[l][r]!=-1)
		return dp[l][r];
	ll k = max(
			a[l] + min(util(a,l+2,r),util(a,l+1,r-1)),
			a[r] + min(util(a,l+1,r-1),util(a,l,r-2))
		);
	dp[l][r]=k;
	return k;
}

//Q link: https://hack.codingblocks.com/app/practice/1/1255/problem

int main()
{
	layout();
	ll n,l,r;
	cin >> n;
	dp = new ll*[n+1];
	for(ll i=0; i<n+1; i++)
	{
		dp[i] = new ll[n+1];
		for(ll j=0; j<n+1; j++)
			dp[i][j]=-1;
	}
	ll a[n];
	vector<ll> res;
	for(ll i=0; i<n; i++)
		cin >> a[i];
	cout << util(a,0,n-1);
}