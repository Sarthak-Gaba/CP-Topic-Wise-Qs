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

ll counter;

void utilMerge(ll a[], ll l, ll h, ll mid)
{
    ll res[h-l+1];
    ll k=0;
    ll i=l;
    ll j=mid+1;
    while(i<=mid && j<=h)
    {
        if(a[i]<=a[j])
            res[k++]=a[i++];
        else
        {
        	counter += mid-i+1;
            res[k++]=a[j++];
        }
    }
    while(i<=mid)
        res[k++]=a[i++];
    while(j<=h)
        res[k++]=a[j++];
    k=0;
    for(i=l; i<=h; i++)
        a[i]=res[k++];
}

void mergeSort(ll a[], ll l, ll h)
{
    if(l>=h)
        return;
    ll mid=(l+h)/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,h);
    utilMerge(a,l,h,mid);
}

int main()
{
	layout();
	ll t;
	cin >> t;
	while(t--)
	{
		counter=0;
		ll n;
		cin >> n;
		ll a[n];
		for(ll i=0; i<n; i++)
			cin >> a[i];
		mergeSort(a,0,n-1);
		cout << counter << endl;
	}
}