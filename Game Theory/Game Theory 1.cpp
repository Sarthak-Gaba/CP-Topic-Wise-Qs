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

// #define mod 1000000007

ll calMex(unordered_set<ll> s)
{
	ll counter = 0;
	while(s.find(counter) != s.end())
		counter++;
	return counter;
}

vector<ll> dp;

ll calGrundy(ll n)
{
	if(dp[n]!=-1)
		return dp[n];
	unordered_set<ll> s;
	s.insert(1);
	for(ll i = 2; i*i<=n; i++)
	{
		if(n%i==0)
		{
			s.insert(calGrundy(i));
			s.insert(calGrundy(n/i));
		}
	}
	dp[n] = calMex(s);
	return dp[n];
}

int main()
{
	layout();
	ll t;
	cin >> t;
	dp = vector<ll>(10000007,-1);
	dp[1] = dp[0] = 0;
	while (t--)
	{
		ll n,m;
		cin >> n >> m;
		if(n%2==0 || calGrundy(m) == 0)
			cout << 2 << endl;
		else
			cout << 1 << endl;
	}	
}