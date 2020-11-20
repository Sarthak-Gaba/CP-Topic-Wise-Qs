#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
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

void addk(vector<int> &v, vector<int> k)
{
	reverse(v.begin(),v.end());
	reverse(k.begin(),k.end());
	int carry=0;
	vector<int> res;
	ll i;
	for(i=0; i<min(v.size(),k.size()); i++)
	{
		ll x = v[i]+k[i]+carry;
		res.push_back(x%10);
		carry=x/10;
	}
	while(i<v.size())
	{
		ll x = v[i]+carry;
		res.push_back(x%10);
		carry=x/10;
		i++;
	}
	while(i<k.size())
	{
		ll x = k[i]+carry;
		res.push_back(x%10);
		carry=x/10;
		i++;
	}
	while(carry)
	{
		res.push_back(carry%10);
		carry=carry/10;
	}
	reverse(res.begin(),res.end());
	// for(int i=0; i<res.size(); i++)
	// 	cout << res[i];
	// cout << endl;
	v=res;
}

void subtract(vector<int> &v, vector<int> k)
{
	reverse(v.begin(),v.end());
	reverse(k.begin(),k.end());
	vector<int> res;
	int carry=0,x;
	for(ll i=0; i<max(v.size(),k.size()); i++)
	{
		v[i]=v[i]-carry;
		carry=0;
		if(i>=k.size())
		{
			if(v[i]<0)
			{
				carry=1;
				res.push_back(10+v[i]);
			}
			else
				res.push_back(v[i]);
			continue;
		}
		if(v[i]>=k[i])
			res.push_back(v[i]-k[i]); 
		else
		{
			carry=1;
			res.push_back(10+v[i]-k[i]);
		}
	}
	reverse(res.begin(),res.end());
	// for(int i=0; i<res.size(); i++)
	// 	cout << res[i];
	v=res;
}

void divide(vector<int> &v, ll n)
{
	vector<int> res;
	ll prev=0, k=0;
	for(ll i=0; i<v.size(); i++)
	{
		if(res.size() && v[i]==0 && prev==0)
		{
			res.push_back(0);
			continue;
		}
		if(v[i]+prev>=n)
		{
			res.push_back((v[i]+prev)/n);
			prev=((v[i]+prev)%n)*10;
		}
		else
		{
			if(i+1==v.size())
				res.push_back(0);
			prev=(prev+v[i])*10;
		}
	}
	v=res;
	// for(auto i:res)
	// 	cout << i;
	// cout << endl;
}

int main()
{
	layout();
	for(int t=0; t<1; t++)
	{
		string s,x;
		cin >> s >> x;
		vector<int> v,k;
		for(ll i=0; i<s.size(); i++)
		{
			v.push_back(s[i]-'0');
		}
		for(ll i=0; i<x.size(); i++)
		{
			k.push_back(x[i]-'0');
		}
		vector<int> res1,res2;
		subtract(v,k);
		divide(v,2);
		// for(int i=0; i<v.size(); i++)
		// 	cout << v[i];
		// cout << endl;
		res1=v;
		addk(v,k);
		res2=v;
		int i=0;
		while(i<res2.size() && res2[i]==0)
			i++;
		for(;i<res2.size(); i++)
			cout << res2[i];
		cout << endl;
		i=0;
		while(i<res1.size() && res1[i]==0)
			i++;
		int q=i;
		for(;i<res1.size(); i++)
			cout << res1[i];
		if(q==i)
			cout << 0;
		cout << endl;
	}	
}
