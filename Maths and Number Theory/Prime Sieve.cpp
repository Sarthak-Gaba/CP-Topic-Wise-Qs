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

ll p=1000007;

void layout()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

bitset<1000007> sieve;

void setSieve() 
{
	for(ll i=1; i<p; i++)
	{
		if(i%2==0)
			sieve[i]=0;
		else
			sieve[i]=1;
	}
	sieve[2]=1;
	sieve[0]=sieve[1]=0;
	for(ll i=3; i<p; i++)
	{
		if(sieve[i]==0)
			continue;
		for(ll j=i*i; j<p; j+=i)
			sieve[j]=0;
	}
}

int main()
{
	layout();
	setSieve();
}