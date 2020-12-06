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

//q link: https://hack.codingblocks.com/app/practice/1/1057/problem

bool isPossible(ll a[], ll n, ll k, ll time)
{
	ll curTime=0;
	for(ll i=0; i<n; i++)
	{
		if(curTime+a[i]>time)
		{
			curTime=a[i];
			k--;
			if(k<0)
				return false;
		}
		else
			curTime += a[i];
	}
	return true;
}

ll minTime(ll a[], ll n, ll k)
{
	ll s = INT_MIN, e = 0, ans, mid;
	for(ll i=0; i<n; i++)
	{
		if(a[i]>s)
			s=a[i];
		e += a[i];
	}
	while(s<=e)
	{
		mid = (s+e)/2;
		if(isPossible(a,n,k,mid))
		{
			ans = mid;
			e = mid-1;
		}
		else
			s = mid+1;
	}
	return ans;
}

int main()
{
	layout();
	ll n,k;
	cin >> k >> n;
	ll a[n];
	for(ll i=0; i<n; i++)
		cin >> a[i];		
	cout << minTime(a,n,k) << endl;
}