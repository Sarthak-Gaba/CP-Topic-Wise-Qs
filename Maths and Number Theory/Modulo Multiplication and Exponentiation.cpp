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

ll multiplyExpo(ll a, ll b, ll n)
{
	ll res=0;
	while(b>0)
	{
		if(b&1)
			res = (res+a)%n;
		a = (a*2)%n;
		b = b>>1; 
	}
	return res;
}

ll modExpo(ll a, ll b, ll n)
{
	ll res=1;
	while(b>0)
	{
		if(b&1)
			res = (multiplyExpo(res,a,n))%n;
		a = (multiplyExpo(a,a,n))%n;
		b = b>>1;
	}
	return res;
}
 
int main()
{
	layout();
}