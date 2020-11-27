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

bitset<40> col, dif, sum;

ll util(ll n, ll i)
{
	if(i-1==n)
	{
		return 1;
	}
	ll counter=0;
	for(ll k=1; k<=n; k++)
	{
		if(!col[k] && !dif[k-i+n] && !sum[i+k])
		{
			col[k]=1;
			dif[k-i+n]=1;
			sum[k+i]=1;
			counter += util(n, i+1);
			col[k]=dif[k-i+n]=sum[k+i]=0;
		}
	}
	return counter;
}

int main()
{
	layout();
	ll n;
	cin >> n;
	// hash col,dif,sum;
	// col.reserve(1024);
	// col.max_load_factor(0.25);
	// dif.reserve(1024);
	// dif.max_load_factor(0.25);
	// sum.reserve(1024);
	// sum.max_load_factor(0.25);
	cout << util(n,1);
}
// [2 4 1 3 ] [3 1 4 2 ]
