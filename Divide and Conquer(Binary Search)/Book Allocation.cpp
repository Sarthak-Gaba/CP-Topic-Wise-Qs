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

// Q link: https://hack.codingblocks.com/app/practice/1/1365/problem

bool canPlace(ll a[], ll n, ll m, ll maxPage)
{
	for(ll i=0; i<n;)
	{
		ll currPage=0;
		while(currPage<=maxPage)
		{
			currPage+=a[i];
			i++;
		}
		i--;
		m--;
		if(m<0)
			return false;
	}
	return true;
}

ll minPage(ll a[], ll n, ll m)
{
	ll pageSum=0,maxm=INT_MIN;
	for(ll i=0; i<n; i++)
	{
		if(a[i]>maxm)
			maxm=a[i];
		pageSum+=a[i];	
	}
	ll s = maxm, e = pageSum, ans, mid;
	while(s<=e)
	{
		mid = (s+e)/2;
		if(canPlace(a,n,m,mid))
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
	ll t;
	cin >> t;
	while(t--)
	{
		ll n,m;
		cin >> n >> m;
		ll a[n];
		for(ll i=0; i<n; i++)
			cin >> a[i];
		cout << minPage(a,n,m) << endl;
	}
}