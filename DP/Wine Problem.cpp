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

ll **dp;

//Q link: https://www.hackerearth.com/problem/algorithm/cookies/description/

ll topDown(ll i, ll j, ll y, ll a[])
{
	if(i==j)
	{
		dp[i][j] = y*a[i];
		return dp[i][j];
	}
	if(dp[i][j]!=-1)
		return dp[i][j];
	ll left = y*a[i] + topDown(i+1,j,y+1,a);
	ll right = y*a[j] + topDown(i,j-1,y+1,a);
	dp[i][j] = max(left,right);
	return dp[i][j];	
}	

ll bottomUp(ll n, ll a[])
{
	for(ll i=0; i<n; i++)
		dp[i][i] = n*a[i];
	for(ll i=1; i<n; i++)
	{
		for(ll j=0; j<n-i; j++)
		{
			ll x = j,y=i+j,year = n-(y-x);
			ll left = year*a[x] + dp[x+1][y];
			ll right = year*a[y] + dp[x][y-1];
			dp[x][y] = max(left,right);
		}
	}
	return dp[0][n-1];
}

int main()
{
	layout();
	ll t;
	cin >> t;
	for(ll k=1; k<=t; k++)
	{
		ll n;
		cin >> n;
		ll a[n];
		dp = new ll*[n+1];
		for(ll i=0; i<=n; i++)
			dp[i] = new ll[n+1];
		for(ll i=0; i<=n; i++)
		{
			for(ll j=0; j<=n; j++)
				dp[i][j]=-1;
		}
		for(ll i=0; i<n; i++)
			cin >> a[i];
		// cout << topDown(0,n-1,1,a) << endl;
		cout << bottomUp(n,a) << endl;
	}
}