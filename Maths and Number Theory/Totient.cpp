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

ll z=1000005;
ll sieve[1000007]={0};

void setSieve() 
{
	sieve[1]=1;
	for(ll i=2; i<z; i++)
	{
		if(sieve[i]!=0)
			continue;
		if(sieve[i]==0)
			sieve[i]=i;
		for(ll j=i*i; j<z; j+=i)
		{
			if(sieve[j]==0)
				sieve[j]=i;
		}
	}
}

int main()
{
	layout();
	setSieve();
	ll t;
	cin >> t;
	while(t--)
	{
		ll n,res;
		cin >> n;
		res=n;
		unordered_map<ll,ll> m;
		while(n>1)
		{
			m[sieve[n]]=1;
			n=n/sieve[n];
		}
		for(auto i:m)
			res = (res-(res/i.first));
		cout << res << endl;
	}
}