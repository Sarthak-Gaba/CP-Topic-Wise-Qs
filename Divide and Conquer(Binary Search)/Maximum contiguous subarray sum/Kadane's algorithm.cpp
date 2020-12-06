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

int main()
{
	layout();
	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		ll a[n];
		for(ll i=0; i<n; i++)
			cin >> a[i];
		int x = a[0],maxm=a[0];
		for(int i=1; i<n; i++)
		{
			if(a[i]+x > a[i])
				x = a[i] + x;
			else
				x = a[i];
			maxm = max(maxm,x);
		}
		cout << maxm << endl;
	}
}