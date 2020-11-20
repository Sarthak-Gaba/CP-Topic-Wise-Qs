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

bool millerRabin(ll n)
{
	if(n==2)
		return true;
	if(n==1 || n%2==0)
		return false;
	ll d=n-1,s=0;
	while(d%2==0)
	{
		s++;
		d=d>>1;
	}
	vector<ll> a({2,3,5,7,11,13,17,19,23});
	for(auto i:a)
	{
		if(i>n-2)
			break;
		ll ad = modExpo(i,d,n);
		if(ad%n==1)
			continue;
		bool prime=false;
		for(ll k=0; k<=s-1; k++)
		{
			ll powk = modExpo(2,k,n);
			ll adk = modExpo(ad,powk,n);
			if(adk%n == n-1 || adk%n == -1)
			{
				prime=true;
				break;
			}
		}
		if(prime==false)
			return false;
	}
	return true;
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
		if(millerRabin(n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}