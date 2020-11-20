#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define mod 1000000000
#define ll long long
#define hash unordered_map<ll,ll>

//Link to problem: https://www.spoj.com/problems/SEQ/

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

vector<vector<ll>> multiplyMatrix(vector<vector<ll>> &m1, vector<vector<ll>> &m2, ll m, ll n, ll c)
{
	vector<vector<ll>> res;
	for(ll i=0; i<m; i++)
	{
		vector<ll> v;
		for(ll j=0; j<n; j++)
		{
			ll x=0;
			for(ll k=0; k<c; k++)
				x+=(m1[i][k]*m2[k][j])%mod;
			v.push_back(x%mod);
		}
		res.push_back(v);
	}
	return res;
}

vector<vector<ll>> matrixExpo(vector<vector<ll>> &T, ll k, ll n)
{
	vector<vector<ll>> a=T;
	vector<vector<ll>> res;
	//setting res as IDENTITY MATRIX
	for(ll i=0; i<k; i++)
	{
		vector<ll> v;
		for(ll j=0; j<k; j++)
		{
			ll x;
			if(i==j)
				x=1;
			else
				x=0;
			v.push_back(x);
		}
		res.push_back(v);
	}
	while(n)
	{
		if(n&1)
		{
			res=multiplyMatrix(res,a,k,k,k);
		}
		a=multiplyMatrix(a,a,k,k,k);
		n=n>>1;
	}
	// for(auto i:res)
	// {
	// 	for(auto j:i)
	// 		cout << j << " ";
	// 	cout << endl;
	// }	
	return res;
}

int main()
{
	layout();
	ll t;
	cin >> t;
	while(t--)
	{
		ll k,n;
		cin >> k;
		ll b[k],c[k];
		for(ll i=0; i<k; i++)
			cin >> b[i];
		for(ll i=0; i<k; i++)
			cin >> c[i];
		cin >> n;
		if(n<=k)
		{
			cout << b[n-1] << endl;
			continue;
		}
		vector<vector<ll>> T;
		for(ll i=0; i<k; i++)
		{
			vector<ll> v;
			for(ll j=0; j<k; j++)
			{
				ll x;
				if(i<k-1)
				{
					if(j-i==1)
						x=1;
					else
						x=0;
				}
				else
				{
					x=c[k-1-j];
				}
				v.push_back(x);
			}
			T.push_back(v);
		}
		// for(auto i:T)
		// {
		// 	for(auto j:i)
		// 		cout << j << " ";
		// 	cout << endl;
		// }	
		// cout << "--------" << endl;
		vector<vector<ll>> z;
		for(ll i=0; i<k; i++)
		{
			vector<ll> v;
			v.push_back(b[i]);
			z.push_back(v);
		}
		vector<vector<ll>> Tn = matrixExpo(T,k,n-k);
		// for(auto i:Tn)
		// {
		// 	for(auto j:i)
		// 		cout << j << " ";
		// 	cout << endl;
		// }	
		// cout << "--------" << endl;
		vector<vector<ll>> res = multiplyMatrix(Tn,z,k,1,k);
		cout << res[k-1][0] << endl;
	}
}
