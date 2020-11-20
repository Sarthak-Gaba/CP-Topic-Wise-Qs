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

#define z 100005
ll primeSieve[z],primeCount[z],mobius[z];

void setMobius()
{
	for(ll i=0; i<z; i++)
	{
		primeSieve[i]=1;
		primeCount[i]=0;
	}
	for(ll i=2; i<z; i++)
	{
		if(primeCount[i])
			continue;
		for(ll j=i; j<z; j+=i)
		{
			primeSieve[j] *= i;
			primeCount[j]++;
		}
	}
	for(ll i=1; i<z; i++)
	{
		if(primeSieve[i]==i)
		{
			if(primeCount[i]%2==0)
				mobius[i]=1;
			else
				mobius[i]=-1;
		}
		else
		{
			mobius[i]=0;
		}
	}
}
 
int main()
{
	layout();
	setMobius();
	ll n;
	cin >> n;
	for(ll i=1; i<=n; i++)
		cout << mobius[i] << endl;
}