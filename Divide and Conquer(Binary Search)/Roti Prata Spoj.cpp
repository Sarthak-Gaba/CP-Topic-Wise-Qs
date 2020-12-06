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

ll z=1000000007;

void layout()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

// Q link: https://www.spoj.com/problems/PRATA/

ll kitniRotis(ll s, ll x)
{
	return ((float)sqrt(8*s*x+x*x)-(float)x)/(float)(2*x);
}

bool canPlace(ll ranks[], ll prata, ll n, ll time)
{
	ll rotis=0;
	for(ll i=0; i<n; i++)
	{
		prata -= kitniRotis(time,ranks[i]);
		if(prata<=0)
			return true;
	}
	return false;
}

ll minTime(ll ranks[], ll prata, ll n)
{
	ll s=0,e = ranks[n-1]*((prata*(prata+1))/2);
	ll ans, mid;
	while(s<=e)
	{
		mid = (s+e)/2;
		if(canPlace(ranks,prata,n,mid))
		{
			ans = mid;
			e = mid-1;
		}
		else
			s = mid+1;
	}
	return ans;
}

int main()
{
	layout();
	ll t;
	cin >> t;
	while(t--)
	{
		ll prata, n;
		cin >> prata >> n;
		ll ranks[n];
		for(ll i=0; i<n; i++)
			cin >> ranks[i];
		sort(ranks,ranks+n);
		cout << minTime(ranks,prata,n) << endl;
	}
}