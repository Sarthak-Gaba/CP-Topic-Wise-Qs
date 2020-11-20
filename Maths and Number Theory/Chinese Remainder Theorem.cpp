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

ll modExpo(ll a, ll b, ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1==1)
			res=(res*a)%p;
		a=(a*a)%p;
		b=b>>1;
	}
	return res;
}

pair<ll,ll> extendedEuclidean(ll a, ll b)
{
	if(b==0)
		return make_pair(1,0);
	pair<ll,ll> p = extendedEuclidean(b,a%b);
	ll x=p.first,y=p.second;
	return make_pair(y,x-((a/b)*y));
}

int main()
{
	layout();
	ll k;
	cin >> k;
	ll num[k],rem[k],prod=1,pp[k],inv[k],ans=0;
	for(ll i=0; i<k; i++)
	{
		cin >> num[i];
		prod*=num[i];
	}
	for(ll i=0; i<k; i++)
		cin >> rem[i];
	for(ll i=0; i<k; i++)
	{
		pp[i] = prod/num[i];
		inv[i] = (extendedEuclidean(pp[i],num[i]).first+num[i])%num[i];
		ans = (ans + (((rem[i]*pp[i])%prod)*inv[i]))%prod;
	}
	cout << ans << endl;
}