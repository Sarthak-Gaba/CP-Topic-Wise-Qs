#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define hash unordered_map<ll,ll>

//Problem: https://www.spoj.com/problems/SPP/

ll mod;

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
				x = (x%mod+((m1[i][k])%mod*(m2[k][j])%mod)%mod)%mod;
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
		ll k,n,m,p,inSum=0;
		cin >> k;
		ll b[k],c[k];
		for(ll i=0; i<k; i++)
		{
			cin >> b[i];
			inSum+=b[i];
		}
		for(ll i=0; i<k; i++)
			cin >> c[i];
		cin >> m >> n >> p;
		mod=p;
		if(n<=k)
		{
			cout << b[n-1] << endl;
			continue;
		}
		vector<vector<ll>> T;
		for(ll i=0; i<=k; i++)
		{
			vector<ll> v;
			for(ll j=0; j<=k; j++)
			{
				ll x;
				if(i>0 && i<k)
				{
					if(j-i==1)
						x=1;
					else
						x=0;
				}
				else
				{
					if(i==0 && j==0)
						x=1;
					else if(i==k && j==0)
						x=0;
					else
						x=c[k-j];
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
		vector<ll> v;
		v.push_back(inSum);
		z.push_back(v);
		for(ll i=0; i<k; i++)
		{
			vector<ll> v;
			v.push_back(b[i]);
			z.push_back(v);
		}
		// for(auto i:z)
		// {
		// 	for(auto j:i)
		// 		cout << j << " ";
		// 	cout << endl;
		// }	
		ll finalAns=0;
		if(m-1<=k)
		{
			for(ll i=0; i<m-1; i++)
				finalAns=(finalAns-b[i])%mod;
		}
		else
		{
			vector<vector<ll>> Tn2 = matrixExpo(T,k+1,m-k-1);
			//vector<vector<ll>> res2 = multiplyMatrix(Tn2,z,k+1,1,k+1);
			for(ll i=0; i<k+1; i++)
			{
				finalAns = (finalAns-(Tn2[0][i]*z[i][0])%mod)%mod;
			}
			//finalAns= (finalAns-res2[0][0])%mod;
		}
		if(n<=k)
		{
			for(ll i=0; i<n; i++)
				finalAns=(finalAns+b[i])%mod;
		}
		else
		{
			vector<vector<ll>> Tn1 = matrixExpo(T,k+1,n-k);
			//vector<vector<ll>> res1 = multiplyMatrix(Tn1,z,k+1,1,k+1);
			for(ll i=0; i<k+1; i++)
			{
				finalAns = (finalAns+(Tn1[0][i]*z[i][0])%mod)%mod;
			}
			//finalAns=(finalAns+res1[0][0])%mod;
		}
		
		cout << finalAns%mod << endl;
	}
}
