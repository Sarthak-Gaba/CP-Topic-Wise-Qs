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

ll util(ll a[], ll l, ll h, ll mid)
{
	if(l==h)
		return a[l];
	ll maxm1=INT_MIN,maxm2=INT_MIN,sum=0;
	for(ll i=mid; i>=l; i--)
	{
		sum+=a[i];
		if(sum>maxm1)
			maxm1=sum;
	}   
	sum=0;
	for(ll i=mid+1; i<=h; i++)
	{
		sum+=a[i];
		if(sum>maxm2)
			maxm2=sum;
	} 
	return maxm1+maxm2;
}

ll maxSubSum(ll a[], ll l, ll h)
{
    if(l>h)
        return INT_MIN;
    ll mid=(l+h)/2,x=INT_MIN,y=INT_MIN;
    if(l!=h)
    {
    	x = maxSubSum(a,l,mid);
    	y = maxSubSum(a,mid+1,h);
    }
    ll z = util(a,l,h,mid);
    return max(z,max(x,y));
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
		ll a[n];
		for(ll i=0; i<n; i++)
			cin >> a[i];
		cout << maxSubSum(a,0,n-1) << endl;
	}
}