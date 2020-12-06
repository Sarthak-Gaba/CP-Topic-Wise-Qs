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

// Q link: https://hack.codingblocks.com/app/practice/1/205/problem

ll counter=0;

ll sizecount(ll N)
{
    if(N==0 || N==1)
        return 1;
    else 
        return (sizecount(N/2)*2)+1;
}


void util(ll n, ll x, ll y, ll l, ll r)
{
	if((x<l && y<l) || (x>r && y>r))
		return;
	ll mid = (x+y)/2;
	if(n%2==1 && mid>=l && mid<=r)
		counter++;
	if(n>1)
	{
		util(n/2,x,mid-1,l,r);
		util(n/2,mid+1,y,l,r);
	}
}

int main()
{
	layout();
	ll n,l,r;
	cin >> n >> l >> r;
	util(n,1,sizecount(n),l,r);
	cout << counter << endl;
}