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

void update(vector<ll> &BIT, ll i, ll n, ll val)
{
	while(i<=n)
	{
		BIT[i]+=val;
		i += (i&(-i));
	}
}

ll query(vector<ll> &BIT, ll i)
{
	ll res=0;
	while(i>0)
	{	
		res+=BIT[i];
		i -= (i&(-i));
	}
	return res;
}

int main()
{
	layout();
	ll t;
	cin >> t;
	while(t--)
	{
		ll n,maxm=INT_MIN,inv=0;
		cin >> n;
		vector<ll> v(n+1);
		for(ll i=0; i<n; i++)
		{
			cin >> v[i];
			maxm = max(maxm,v[i]);
		}
		vector<ll> BIT(maxm+1,0);
		for(ll i=0; i<n; i++)
		{
			inv += query(BIT,maxm) - query(BIT,v[i]);
			update(BIT,v[i],maxm,1);
		}
		cout << inv << endl;
	}
}