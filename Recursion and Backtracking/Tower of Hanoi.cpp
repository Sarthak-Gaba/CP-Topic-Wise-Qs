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

void TOH(ll i, ll j, ll n)
{
	if(n==1)
	{
		cout << i << " to " << j << endl;
		return;
	}
	TOH(i,6-i-j,n-1);
	cout << i << " to " << j << endl;
	TOH(6-i-j,j,n-1);
}

int main()
{
	layout();
	TOH(1,3,6);
}