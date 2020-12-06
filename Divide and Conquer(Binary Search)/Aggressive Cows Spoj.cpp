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

bool canPlace(ll n, ll c, ll gap, ll a[])
{
	ll prev;
	for(ll i=0; i<n; i++)
	{
		if(c==0)
			break;
		if(i==0)
		{
			prev=a[i];
			c--;
		}
		if(a[i]-prev>=gap)
		{
			prev=a[i];
			c--;
		}
	}
	if(c==0)
		return true;
	return false;
}

ll minGap(ll n,ll c, ll a[])
{
	ll s = 0, e = a[n-1]-a[0], ans, mid;
	while(s<=e)
	{
		mid = (s+e)/2;
		bool b = canPlace(n,c,mid,a);
		if(!b)
			e = mid-1;
		else
		{
			ans = mid;
			s = mid+1;
		}
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
		ll n,c;
		cin >> n >> c;
		ll a[n];
		for(ll i=0; i<n; i++)
			cin >> a[i];
		sort(a,a+n);
		cout << minGap(n,c,a) << endl;
	}
}